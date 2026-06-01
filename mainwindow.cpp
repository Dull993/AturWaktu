#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{//constuctor
    ui->setupUi(this);
    //UI
    this->setStyleSheet(R"(
    QWidget {
        background-color: #121212;
        color: white;
        font-size: 14px;
    }

    QPushButton {
        background-color: #1f1f1f;
        border-radius: 10px;
        padding: 8px;
    }

    QPushButton:hover {
        background-color: #2c2c2c;
    }

    QPushButton:pressed {
        background-color: #3a3a3a;
    }
)");
    ui->labelStopwatch->setStyleSheet("font-size: 36px; font-weight: bold;");
    ui->labelTimer->setStyleSheet("font-size: 30px;");

    ui->btnStartSW->setStyleSheet("background-color: #00c853; color: black;");
    ui->btnResetSW->setStyleSheet("background-color: #d50000; color: white;");

    ui->btnStartTimer->setStyleSheet("background-color: #00c853; color: black;");
    ui->btnResetTimer->setStyleSheet("background-color: #d50000; color: white;");

    ui->btnAddAlarm->setStyleSheet("background-color: #2962ff;");
    ui->btnDeleteAlarm->setStyleSheet("background-color: #ff1744;");

    ui->listAlarm->setStyleSheet(R"(
    QListWidget {
        background-color: #1e1e1e;
        border: none;
    }
    QListWidget::item {
        padding: 10px;
    }
    QListWidget::item:selected {
        background-color: #2962ff;
    }
)");



    timer = new QTimer(this); //Stopwatch

    connect(timer, &QTimer::timeout, this, &MainWindow::updateWaktu);

    connect(ui->btnStartSW, &QPushButton::clicked, this, [=]() {

        if (isRunning) {
            // PAUSE
            timer->stop();
            ui->btnStartSW->setText("Start");
            isRunning = false;
        } else {
            // START / RESUME
            timer->start(1000);
            ui->btnStartSW->setText("Pause");
            isRunning = true;
        }
    });

    connect(ui->btnResetSW, &QPushButton::clicked, this, [=]() {
        timer->stop();
        detik = 0;
        isRunning = false;

        ui->btnStartSW->setText("Start");
        ui->labelStopwatch->setText("00:00:00");
    });


    countdownTimer = new QTimer(this); //Timer

    connect(countdownTimer, &QTimer::timeout, this, &MainWindow::updateTimer);

    connect(ui->btnStartTimer, &QPushButton::clicked, this, [=]() {

        // kalau lagi jalan → pause
        if (isTimerRunning) {
            countdownTimer->stop();
            ui->btnStartTimer->setText("Start");
            isTimerRunning = false;
        }
        // kalau lagi berhenti → start / resume
        else {

            // ambil waktu HANYA kalau belum pernah start
            if (sisaDetik == 0) {
                QTime waktu = ui->timeEditTimer->time();
                sisaDetik = waktu.hour()*3600 + waktu.minute()*60 + waktu.second();
            }

            countdownTimer->start(1000);
            ui->btnStartTimer->setText("Pause");
            isTimerRunning = true;
        }
    });
    connect(ui->btnResetTimer, &QPushButton::clicked, this, [=]() {
        countdownTimer->stop();
        sisaDetik = 0;
        isTimerRunning = false;

        ui->btnStartTimer->setText("Start");
        ui->labelTimer->setText("00:00:00");
    });

    connect(ui->btnAddAlarm, &QPushButton::clicked, this, &MainWindow::addAlarm); // alarm
    alarmTimer = new QTimer(this);

    // jalan setiap 1 detik
    alarmTimer->start(1000);

    connect(alarmTimer, &QTimer::timeout, this, &MainWindow::checkAlarm);
    connect(ui->btnDeleteAlarm, &QPushButton::clicked, this, &MainWindow::deleteAlarm);

}
void MainWindow::updateWaktu() { //stopwatch
    detik++;

    QTime t(0,0);
    t = t.addSecs(detik);

    ui->labelStopwatch->setText(t.toString("HH:mm:ss"));
}

void MainWindow::updateTimer() { //timer

    if (sisaDetik > 0) {
        sisaDetik--;

        QTime t(0,0);
        t = t.addSecs(sisaDetik);

        ui->labelTimer->setText(t.toString("HH:mm:ss"));
    }
    else {
        countdownTimer->stop();
        isTimerRunning = false;

        ui->btnStartTimer->setText("Start");
        ui->labelTimer->setText("DONE!");
    }
}

void MainWindow::addAlarm() {

    // ambil waktu dari input
    QTime waktu = ui->timeEditAlarm->time();

    // ubah jadi text
    QString teks = waktu.toString("HH:mm:ss");

    // masukkan ke list
    ui->listAlarm->addItem(teks);
}

void MainWindow::checkAlarm() {

    // ambil waktu sekarang
    QString sekarang = QTime::currentTime().toString("HH:mm:ss");

    // cek semua alarm di list
    for (int i = 0; i < ui->listAlarm->count(); i++) {

        if (ui->listAlarm->item(i)->text() == sekarang) {

            QMessageBox::information(this, "Alarm", "⏰ WAKTU SUDAH TIBA!");
        }
    }
}
void MainWindow::deleteAlarm() {

    // ambil item yang dipilih
    QListWidgetItem *item = ui->listAlarm->currentItem();

    // kalau tidak ada yang dipilih
    if (!item) return;

    // hapus item
    delete item;
}
MainWindow::~MainWindow()
{
    delete ui;
}
