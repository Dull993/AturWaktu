#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ── Styling TabWidget & TabBar (harus di-set lewat widget, bukan global) ──
    ui->tabAturWaktu->setStyleSheet(R"(
        QTabWidget::pane {
            border: none;
            background-color: #f8f7fc;
        }
        QTabBar::tab {
            background-color: #ede9f8;
            color: #6b6880;
            font-size: 13px;
            padding: 8px 28px;
            margin: 2px 3px;
            border-radius: 10px;
            min-width: 100px;
        }
        QTabBar::tab:selected {
            background-color: #8c73f2;
            color: #ffffff;
            font-weight: bold;
        }
        QTabBar::tab:hover:!selected {
            background-color: #ddd6f7;
        }
    )");

    // ── Background utama ──
    this->centralWidget()->setStyleSheet("background-color: #f8f7fc;");

    // ── Label ──
    ui->labelTitle->setStyleSheet(
        "font-size: 22px; font-weight: bold; color: #14121e;");
    ui->labelStopwatch->setStyleSheet(
        "font-size: 52px; font-weight: bold; color: #14121e;");
    ui->labelTimer->setStyleSheet(
        "font-size: 52px; font-weight: bold; color: #14121e;");
    ui->labelTimerRemaining->setStyleSheet(
        "font-size: 12px; color: #a09eaa;");
    ui->labelSWHeader->setStyleSheet(
        "font-size: 12px; font-weight: bold; color: #a09eaa; letter-spacing: 1px;");
    ui->labelTimerHeader->setStyleSheet(
        "font-size: 12px; font-weight: bold; color: #a09eaa; letter-spacing: 1px;");

    // ── Tombol Stopwatch ──
    ui->btnStartSW->setStyleSheet(
        "background-color: #8c73f2; color: white; border: none;"
        "border-radius: 10px; padding: 10px 20px; font-weight: bold;");
    ui->btnLapSW->setStyleSheet(
        "background-color: #fff0f6; color: #fa73a6;"
        "border: 1px solid #fac0d5; border-radius: 10px; padding: 10px 20px; font-weight: bold;");
    ui->btnResetSW->setStyleSheet(
        "background-color: #ede9f8; color: #8c73f2;"
        "border: 1px solid #c9bff5; border-radius: 10px; padding: 10px 20px; font-weight: bold;");

    // ── Tombol Timer ──
    ui->btnStartTimer->setStyleSheet(
        "background-color: #8c73f2; color: white; border: none;"
        "border-radius: 10px; padding: 10px 20px; font-weight: bold;");
    ui->btnResetTimer->setStyleSheet(
        "background-color: #ede9f8; color: #8c73f2;"
        "border: 1px solid #c9bff5; border-radius: 10px; padding: 10px 20px; font-weight: bold;");

    // ── Preset Timer ──
    QString presetStyle =
        "background-color: #ede9f8; color: #8c73f2;"
        "border: 1px solid #c9bff5; border-radius: 16px;"
        "padding: 6px 14px; font-weight: bold;";
    ui->btnPreset5->setStyleSheet(presetStyle);
    ui->btnPreset10->setStyleSheet(presetStyle);
    ui->btnPreset15->setStyleSheet(presetStyle);
    ui->btnPreset30->setStyleSheet(presetStyle);

    // ── Tombol Alarm ──
    ui->btnAddAlarm->setStyleSheet(
        "background-color: #8c73f2; color: white; border: none;"
        "border-radius: 10px; padding: 10px 20px; font-weight: bold;");
    ui->btnDeleteAlarm->setStyleSheet(
        "background-color: #ede9f8; color: #8c73f2;"
        "border: 1px solid #c9bff5; border-radius: 10px; padding: 10px 20px; font-weight: bold;");

    // ── List Alarm ──
    ui->listAlarm->setStyleSheet(R"(
        QListWidget {
            background-color: #ffffff;
            border: 1px solid #e0ddf0;
            border-radius: 12px;
            padding: 4px;
            color: #14121e;
        }
        QListWidget::item { padding: 8px 10px; border-radius: 8px; }
        QListWidget::item:selected { background-color: #ede9f8; }
        QListWidget::item:hover { background-color: #f3f0fb; }
    )");

    // ── List Lap ──
    ui->listLap->setStyleSheet(R"(
        QListWidget {
            background-color: #ffffff;
            border: 1px solid #e0ddf0;
            border-radius: 12px;
            padding: 4px;
            color: #14121e;
        }
        QListWidget::item { padding: 6px 10px; border-radius: 8px; }
        QListWidget::item:selected { background-color: #fff0f6; color: #fa73a6; }
        QListWidget::item:hover { background-color: #f3f0fb; }
    )");

    // ══════════════════════════════════════════════
    //  STOPWATCH  (interval 10ms → centisecond)
    // ══════════════════════════════════════════════
    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateWaktu);

    connect(ui->btnStartSW, &QPushButton::clicked, this, [=]() {
        if (isRunning) {
            timer->stop();
            ui->btnStartSW->setText("Start");
            isRunning = false;
        } else {
            timer->start();
            ui->btnStartSW->setText("Pause");
            isRunning = true;
        }
    });

    connect(ui->btnResetSW, &QPushButton::clicked, this, [=]() {
        timer->stop();
        isRunning = false;
        detik     = 0;
        lapCount  = 0;
        ui->btnStartSW->setText("Start");
        ui->labelStopwatch->setText("00:00.00");
        ui->listLap->clear();
    });

    // LAP — catat waktu saat ini ke listLap
    connect(ui->btnLapSW, &QPushButton::clicked, this, [=]() {
        if (!isRunning && detik == 0) return; // belum mulai sama sekali
        lapCount++;
        int cs   =  detik % 100;
        int secs = (detik / 100) % 60;
        int mins = (detik / 100) / 60;
        QString teks = QString("Lap %1    %2:%3.%4")
                           .arg(lapCount,  2, 10, QChar('0'))
                           .arg(mins,      2, 10, QChar('0'))
                           .arg(secs,      2, 10, QChar('0'))
                           .arg(cs,        2, 10, QChar('0'));
        ui->listLap->addItem(teks);
        ui->listLap->scrollToBottom();
    });

    // ══════════════════════════════════════════════
    //  TIMER
    // ══════════════════════════════════════════════
    countdownTimer = new QTimer(this);
    countdownTimer->setInterval(1000);
    connect(countdownTimer, &QTimer::timeout, this, &MainWindow::updateTimer);

    connect(ui->btnStartTimer, &QPushButton::clicked, this, [=]() {
        if (isTimerRunning) {
            countdownTimer->stop();
            ui->btnStartTimer->setText("Start");
            isTimerRunning = false;
        } else {
            if (sisaDetik == 0) {
                QTime w = ui->timeEditTimer->time();
                sisaDetik = w.hour()*3600 + w.minute()*60 + w.second();
                if (sisaDetik == 0) return;
            }
            countdownTimer->start();
            ui->btnStartTimer->setText("Pause");
            isTimerRunning = true;
        }
    });

    connect(ui->btnResetTimer, &QPushButton::clicked, this, [=]() {
        countdownTimer->stop();
        isTimerRunning = false;
        sisaDetik = 0;
        ui->btnStartTimer->setText("Start");
        ui->labelTimer->setText("00:00:00");
        ui->labelTimerRemaining->setText("remaining");
    });

    // Preset
    auto setPreset = [=](int menit) {
        countdownTimer->stop();
        isTimerRunning = false;
        sisaDetik = menit * 60;
        ui->btnStartTimer->setText("Start");
        ui->timeEditTimer->setTime(QTime(0, menit, 0));
        QTime t(0, 0);
        t = t.addSecs(sisaDetik);
        ui->labelTimer->setText(t.toString("HH:mm:ss"));
        ui->labelTimerRemaining->setText("remaining");
    };
    connect(ui->btnPreset5,  &QPushButton::clicked, this, [=]() { setPreset(5);  });
    connect(ui->btnPreset10, &QPushButton::clicked, this, [=]() { setPreset(10); });
    connect(ui->btnPreset15, &QPushButton::clicked, this, [=]() { setPreset(15); });
    connect(ui->btnPreset30, &QPushButton::clicked, this, [=]() { setPreset(30); });

    // ══════════════════════════════════════════════
    //  ALARM
    // ══════════════════════════════════════════════
    connect(ui->btnAddAlarm,    &QPushButton::clicked, this, &MainWindow::addAlarm);
    connect(ui->btnDeleteAlarm, &QPushButton::clicked, this, &MainWindow::deleteAlarm);

    alarmTimer = new QTimer(this);
    alarmTimer->setInterval(1000);
    alarmTimer->start();
    connect(alarmTimer, &QTimer::timeout, this, &MainWindow::checkAlarm);
}

// ── Stopwatch tick ──
void MainWindow::updateWaktu()
{
    detik++;
    int cs   =  detik % 100;
    int secs = (detik / 100) % 60;
    int mins = (detik / 100) / 60;
    ui->labelStopwatch->setText(
        QString("%1:%2.%3")
            .arg(mins, 2, 10, QChar('0'))
            .arg(secs, 2, 10, QChar('0'))
            .arg(cs,   2, 10, QChar('0')));
}

// ── Timer countdown ──
void MainWindow::updateTimer()
{
    if (sisaDetik > 0) {
        sisaDetik--;
        QTime t(0, 0);
        t = t.addSecs(sisaDetik);
        ui->labelTimer->setText(t.toString("HH:mm:ss"));
    } else {
        countdownTimer->stop();
        isTimerRunning = false;
        ui->btnStartTimer->setText("Start");
        ui->labelTimer->setText("SELESAI!");
        ui->labelTimerRemaining->setText("");
        QMessageBox::information(this, "Timer", "Waktu habis!");
    }
}

// ── Alarm ──
void MainWindow::addAlarm()
{
    QTime waktu = ui->timeEditAlarm->time();
    ui->listAlarm->addItem(waktu.toString("HH:mm:ss"));
}

void MainWindow::checkAlarm()
{
    QString sekarang = QTime::currentTime().toString("HH:mm:ss");
    for (int i = 0; i < ui->listAlarm->count(); i++) {
        if (ui->listAlarm->item(i)->text() == sekarang) {
            QMessageBox::information(this, "Alarm", "WAKTU SUDAH TIBA!");
        }
    }
}

void MainWindow::deleteAlarm()
{
    QListWidgetItem *item = ui->listAlarm->currentItem();
    if (!item) return;
    delete item;
}

MainWindow::~MainWindow()
{
    delete ui;
}
