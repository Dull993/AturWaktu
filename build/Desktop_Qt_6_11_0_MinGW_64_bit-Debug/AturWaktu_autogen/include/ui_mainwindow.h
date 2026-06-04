/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainVLayout;
    QHBoxLayout *headerLayout;
    QLabel *labelTitle;
    QSpacerItem *headerSpacer;
    QTabWidget *tabAturWaktu;
    QWidget *tabAlarm;
    QHBoxLayout *alarmHLayout;
    QVBoxLayout *alarmListVLayout;
    QLabel *labelAlarmList;
    QListWidget *listAlarm;
    QVBoxLayout *alarmControlVLayout;
    QSpacerItem *alarmTopSpacer;
    QLabel *labelSetAlarm;
    QTimeEdit *timeEditAlarm;
    QPushButton *btnAddAlarm;
    QPushButton *btnDeleteAlarm;
    QSpacerItem *alarmBottomSpacer;
    QWidget *tabTimer;
    QVBoxLayout *timerVLayout;
    QSpacerItem *timerTopSpacer;
    QLabel *labelTimerHeader;
    QHBoxLayout *timerInputHLayout;
    QSpacerItem *spacerItem;
    QTimeEdit *timeEditTimer;
    QSpacerItem *spacerItem1;
    QLabel *labelTimer;
    QLabel *labelTimerRemaining;
    QHBoxLayout *timerPresetHLayout;
    QSpacerItem *spacerItem2;
    QPushButton *btnPreset5;
    QPushButton *btnPreset10;
    QPushButton *btnPreset15;
    QPushButton *btnPreset30;
    QSpacerItem *spacerItem3;
    QHBoxLayout *timerBtnHLayout;
    QSpacerItem *spacerItem4;
    QPushButton *btnStartTimer;
    QPushButton *btnResetTimer;
    QSpacerItem *spacerItem5;
    QSpacerItem *timerBottomSpacer;
    QWidget *tabStopwatch;
    QVBoxLayout *swVLayout;
    QSpacerItem *swTopSpacer;
    QLabel *labelSWHeader;
    QLabel *labelStopwatch;
    QHBoxLayout *swBtnHLayout;
    QSpacerItem *spacerItem6;
    QPushButton *btnStartSW;
    QPushButton *btnLapSW;
    QPushButton *btnResetSW;
    QSpacerItem *spacerItem7;
    QListWidget *listLap;
    QSpacerItem *swBottomSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow {\n"
"    background-color: #f8f7fc;\n"
"}\n"
"QWidget#centralwidget {\n"
"    background-color: #f8f7fc;\n"
"}\n"
"QTabWidget::pane {\n"
"    border: none;\n"
"    background-color: #f8f7fc;\n"
"    border-radius: 16px;\n"
"}\n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"}\n"
"QTabBar::tab {\n"
"    background-color: #ede9f8;\n"
"    color: #6b6880;\n"
"    font-family: \"Inter\";\n"
"    font-size: 13px;\n"
"    padding: 8px 28px;\n"
"    margin: 2px 3px;\n"
"    border-radius: 10px;\n"
"    min-width: 100px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #8c73f2, stop:1 #c099ff);\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"QTabBar::tab:hover:!selected {\n"
"    background-color: #ddd6f7;\n"
"    color: #3d3a52;\n"
"}\n"
"QListWidget {\n"
"    background-color: #ffffff;\n"
"    border: 1.5px solid #e0ddf0;\n"
"    border-radius: 12px;\n"
"    padding: 6px;\n"
"    font-family: \"Inter\";\n"
"    font-size: 14px"
                        ";\n"
"    color: #14121e;\n"
"    outline: none;\n"
"}\n"
"QListWidget::item {\n"
"    padding: 8px 10px;\n"
"    border-radius: 8px;\n"
"    margin: 2px 0px;\n"
"}\n"
"QListWidget::item:selected {\n"
"    background-color: #ede9f8;\n"
"    color: #14121e;\n"
"}\n"
"QListWidget::item:hover {\n"
"    background-color: #f3f0fb;\n"
"}\n"
"QTimeEdit {\n"
"    background-color: #ffffff;\n"
"    border: 1.5px solid #e0ddf0;\n"
"    border-radius: 10px;\n"
"    padding: 8px 12px;\n"
"    font-family: \"Inter\";\n"
"    font-size: 16px;\n"
"    color: #14121e;\n"
"}\n"
"QTimeEdit::up-button, QTimeEdit::down-button {\n"
"    width: 18px;\n"
"    border-radius: 5px;\n"
"    background: #ede9f8;\n"
"}\n"
"QPushButton {\n"
"    border-radius: 10px;\n"
"    padding: 10px 20px;\n"
"    font-family: \"Inter\";\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton#btnAddAlarm {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #8c73f2, stop:1 #c099ff);\n"
"    color: #ffffff;\n"
"    borde"
                        "r: none;\n"
"}\n"
"QPushButton#btnAddAlarm:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #7a60e0, stop:1 #b088ee);\n"
"}\n"
"QPushButton#btnDeleteAlarm {\n"
"    background-color: #ede9f8;\n"
"    color: #8c73f2;\n"
"    border: 1.5px solid #c9bff5;\n"
"}\n"
"QPushButton#btnDeleteAlarm:hover {\n"
"    background-color: #ddd6f7;\n"
"}\n"
"QPushButton#btnStartSW, QPushButton#btnStartTimer {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #8c73f2, stop:1 #c099ff);\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton#btnStartSW:hover, QPushButton#btnStartTimer:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #7a60e0, stop:1 #b088ee);\n"
"}\n"
"QPushButton#btnResetSW, QPushButton#btnResetTimer {\n"
"    background-color: #ede9f8;\n"
"    color: #8c73f2;\n"
"    border: 1.5px solid #c9bff5;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton#btnResetSW:hover, QPushButton#btnResetTimer:hover {\n"
"    backgrou"
                        "nd-color: #ddd6f7;\n"
"}\n"
"QPushButton#btnLapSW {\n"
"    background-color: #fff0f6;\n"
"    color: #fa73a6;\n"
"    border: 1.5px solid #fac0d5;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton#btnLapSW:hover {\n"
"    background-color: #ffe4f0;\n"
"}\n"
"QPushButton#btnPreset5, QPushButton#btnPreset10, QPushButton#btnPreset15, QPushButton#btnPreset30 {\n"
"    background-color: #ede9f8;\n"
"    color: #8c73f2;\n"
"    border: 1.5px solid #c9bff5;\n"
"    padding: 6px 14px;\n"
"    min-width: 54px;\n"
"    border-radius: 18px;\n"
"}\n"
"QPushButton#btnPreset5:hover, QPushButton#btnPreset10:hover,\n"
"QPushButton#btnPreset15:hover, QPushButton#btnPreset30:hover {\n"
"    background-color: #ddd6f7;\n"
"}\n"
"QLabel#labelTitle {\n"
"    font-family: \"Inter\";\n"
"    font-size: 22px;\n"
"    font-weight: bold;\n"
"    color: #14121e;\n"
"    letter-spacing: -0.3px;\n"
"}\n"
"QLabel#labelStopwatch {\n"
"    font-family: \"Inter\";\n"
"    font-size: 52px;\n"
"    color: #14121e;\n"
"    letter-spacing: -1.5px;\n"
""
                        "}\n"
"QLabel#labelTimer {\n"
"    font-family: \"Inter\";\n"
"    font-size: 52px;\n"
"    color: #14121e;\n"
"    letter-spacing: -1px;\n"
"}\n"
"QLabel#labelTimerRemaining {\n"
"    font-family: \"Inter\";\n"
"    font-size: 11px;\n"
"    color: #a09eaa;\n"
"}\n"
"QLabel#labelSWHeader, QLabel#labelTimerHeader {\n"
"    font-family: \"Inter\";\n"
"    font-size: 13px;\n"
"    color: #a09eaa;\n"
"    font-weight: bold;\n"
"    letter-spacing: 1.5px;\n"
"}\n"
"QFrame#divider {\n"
"    color: #e0ddf0;\n"
"}\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainVLayout = new QVBoxLayout(centralwidget);
        mainVLayout->setSpacing(16);
        mainVLayout->setObjectName("mainVLayout");
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName("headerLayout");
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName("labelTitle");

        headerLayout->addWidget(labelTitle);

        headerSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerLayout->addItem(headerSpacer);


        mainVLayout->addLayout(headerLayout);

        tabAturWaktu = new QTabWidget(centralwidget);
        tabAturWaktu->setObjectName("tabAturWaktu");
        tabAturWaktu->setTabPosition(QTabWidget::TabPosition::North);
        tabAturWaktu->setDocumentMode(false);
        tabAlarm = new QWidget();
        tabAlarm->setObjectName("tabAlarm");
        alarmHLayout = new QHBoxLayout(tabAlarm);
        alarmHLayout->setSpacing(20);
        alarmHLayout->setObjectName("alarmHLayout");
        alarmListVLayout = new QVBoxLayout();
        alarmListVLayout->setSpacing(10);
        alarmListVLayout->setObjectName("alarmListVLayout");
        labelAlarmList = new QLabel(tabAlarm);
        labelAlarmList->setObjectName("labelAlarmList");

        alarmListVLayout->addWidget(labelAlarmList);

        listAlarm = new QListWidget(tabAlarm);
        listAlarm->setObjectName("listAlarm");

        alarmListVLayout->addWidget(listAlarm);


        alarmHLayout->addLayout(alarmListVLayout);

        alarmControlVLayout = new QVBoxLayout();
        alarmControlVLayout->setSpacing(12);
        alarmControlVLayout->setObjectName("alarmControlVLayout");
        alarmTopSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        alarmControlVLayout->addItem(alarmTopSpacer);

        labelSetAlarm = new QLabel(tabAlarm);
        labelSetAlarm->setObjectName("labelSetAlarm");

        alarmControlVLayout->addWidget(labelSetAlarm);

        timeEditAlarm = new QTimeEdit(tabAlarm);
        timeEditAlarm->setObjectName("timeEditAlarm");
        timeEditAlarm->setAlignment(Qt::AlignmentFlag::AlignCenter);

        alarmControlVLayout->addWidget(timeEditAlarm);

        btnAddAlarm = new QPushButton(tabAlarm);
        btnAddAlarm->setObjectName("btnAddAlarm");

        alarmControlVLayout->addWidget(btnAddAlarm);

        btnDeleteAlarm = new QPushButton(tabAlarm);
        btnDeleteAlarm->setObjectName("btnDeleteAlarm");

        alarmControlVLayout->addWidget(btnDeleteAlarm);

        alarmBottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        alarmControlVLayout->addItem(alarmBottomSpacer);


        alarmHLayout->addLayout(alarmControlVLayout);

        tabAturWaktu->addTab(tabAlarm, QString());
        tabTimer = new QWidget();
        tabTimer->setObjectName("tabTimer");
        timerVLayout = new QVBoxLayout(tabTimer);
        timerVLayout->setSpacing(16);
        timerVLayout->setObjectName("timerVLayout");
        timerTopSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        timerVLayout->addItem(timerTopSpacer);

        labelTimerHeader = new QLabel(tabTimer);
        labelTimerHeader->setObjectName("labelTimerHeader");
        labelTimerHeader->setAlignment(Qt::AlignmentFlag::AlignCenter);

        timerVLayout->addWidget(labelTimerHeader);

        timerInputHLayout = new QHBoxLayout();
        timerInputHLayout->setObjectName("timerInputHLayout");
        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        timerInputHLayout->addItem(spacerItem);

        timeEditTimer = new QTimeEdit(tabTimer);
        timeEditTimer->setObjectName("timeEditTimer");
        timeEditTimer->setAlignment(Qt::AlignmentFlag::AlignCenter);

        timerInputHLayout->addWidget(timeEditTimer);

        spacerItem1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        timerInputHLayout->addItem(spacerItem1);


        timerVLayout->addLayout(timerInputHLayout);

        labelTimer = new QLabel(tabTimer);
        labelTimer->setObjectName("labelTimer");
        labelTimer->setAlignment(Qt::AlignmentFlag::AlignCenter);

        timerVLayout->addWidget(labelTimer);

        labelTimerRemaining = new QLabel(tabTimer);
        labelTimerRemaining->setObjectName("labelTimerRemaining");
        labelTimerRemaining->setAlignment(Qt::AlignmentFlag::AlignCenter);

        timerVLayout->addWidget(labelTimerRemaining);

        timerPresetHLayout = new QHBoxLayout();
        timerPresetHLayout->setObjectName("timerPresetHLayout");
        spacerItem2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        timerPresetHLayout->addItem(spacerItem2);

        btnPreset5 = new QPushButton(tabTimer);
        btnPreset5->setObjectName("btnPreset5");

        timerPresetHLayout->addWidget(btnPreset5);

        btnPreset10 = new QPushButton(tabTimer);
        btnPreset10->setObjectName("btnPreset10");

        timerPresetHLayout->addWidget(btnPreset10);

        btnPreset15 = new QPushButton(tabTimer);
        btnPreset15->setObjectName("btnPreset15");

        timerPresetHLayout->addWidget(btnPreset15);

        btnPreset30 = new QPushButton(tabTimer);
        btnPreset30->setObjectName("btnPreset30");

        timerPresetHLayout->addWidget(btnPreset30);

        spacerItem3 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        timerPresetHLayout->addItem(spacerItem3);


        timerVLayout->addLayout(timerPresetHLayout);

        timerBtnHLayout = new QHBoxLayout();
        timerBtnHLayout->setObjectName("timerBtnHLayout");
        spacerItem4 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        timerBtnHLayout->addItem(spacerItem4);

        btnStartTimer = new QPushButton(tabTimer);
        btnStartTimer->setObjectName("btnStartTimer");

        timerBtnHLayout->addWidget(btnStartTimer);

        btnResetTimer = new QPushButton(tabTimer);
        btnResetTimer->setObjectName("btnResetTimer");

        timerBtnHLayout->addWidget(btnResetTimer);

        spacerItem5 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        timerBtnHLayout->addItem(spacerItem5);


        timerVLayout->addLayout(timerBtnHLayout);

        timerBottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        timerVLayout->addItem(timerBottomSpacer);

        tabAturWaktu->addTab(tabTimer, QString());
        tabStopwatch = new QWidget();
        tabStopwatch->setObjectName("tabStopwatch");
        swVLayout = new QVBoxLayout(tabStopwatch);
        swVLayout->setSpacing(16);
        swVLayout->setObjectName("swVLayout");
        swTopSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        swVLayout->addItem(swTopSpacer);

        labelSWHeader = new QLabel(tabStopwatch);
        labelSWHeader->setObjectName("labelSWHeader");
        labelSWHeader->setAlignment(Qt::AlignmentFlag::AlignCenter);

        swVLayout->addWidget(labelSWHeader);

        labelStopwatch = new QLabel(tabStopwatch);
        labelStopwatch->setObjectName("labelStopwatch");
        labelStopwatch->setAlignment(Qt::AlignmentFlag::AlignCenter);

        swVLayout->addWidget(labelStopwatch);

        swBtnHLayout = new QHBoxLayout();
        swBtnHLayout->setObjectName("swBtnHLayout");
        spacerItem6 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        swBtnHLayout->addItem(spacerItem6);

        btnStartSW = new QPushButton(tabStopwatch);
        btnStartSW->setObjectName("btnStartSW");

        swBtnHLayout->addWidget(btnStartSW);

        btnLapSW = new QPushButton(tabStopwatch);
        btnLapSW->setObjectName("btnLapSW");

        swBtnHLayout->addWidget(btnLapSW);

        btnResetSW = new QPushButton(tabStopwatch);
        btnResetSW->setObjectName("btnResetSW");

        swBtnHLayout->addWidget(btnResetSW);

        spacerItem7 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        swBtnHLayout->addItem(spacerItem7);


        swVLayout->addLayout(swBtnHLayout);

        listLap = new QListWidget(tabStopwatch);
        listLap->setObjectName("listLap");

        swVLayout->addWidget(listLap);

        swBottomSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        swVLayout->addItem(swBottomSpacer);

        tabAturWaktu->addTab(tabStopwatch, QString());

        mainVLayout->addWidget(tabAturWaktu);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabAturWaktu->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Atur Waktu", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "AturWaktu", nullptr));
        labelAlarmList->setStyleSheet(QCoreApplication::translate("MainWindow", "font-family: 'Inter'; font-size: 13px; font-weight: bold; color: #6b6880; letter-spacing: 1px;", nullptr));
        labelAlarmList->setText(QCoreApplication::translate("MainWindow", "Daftar Alarm", nullptr));
        labelSetAlarm->setStyleSheet(QCoreApplication::translate("MainWindow", "font-family: 'Inter'; font-size: 13px; font-weight: bold; color: #6b6880; letter-spacing: 1px;", nullptr));
        labelSetAlarm->setText(QCoreApplication::translate("MainWindow", "Atur Waktu Alarm", nullptr));
        timeEditAlarm->setDisplayFormat(QCoreApplication::translate("MainWindow", "HH:mm:ss", nullptr));
        btnAddAlarm->setText(QCoreApplication::translate("MainWindow", "\357\274\213  Tambah Alarm", nullptr));
        btnDeleteAlarm->setText(QCoreApplication::translate("MainWindow", "Hapus Alarm", nullptr));
        tabAturWaktu->setTabText(tabAturWaktu->indexOf(tabAlarm), QCoreApplication::translate("MainWindow", "Alarm", nullptr));
        labelTimerHeader->setText(QCoreApplication::translate("MainWindow", "TIMER", nullptr));
        timeEditTimer->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 20px; padding: 10px 20px; min-width: 160px;", nullptr));
        timeEditTimer->setDisplayFormat(QCoreApplication::translate("MainWindow", "HH:mm:ss", nullptr));
        labelTimer->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        labelTimerRemaining->setText(QCoreApplication::translate("MainWindow", "remaining", nullptr));
        btnPreset5->setText(QCoreApplication::translate("MainWindow", "5m", nullptr));
        btnPreset10->setText(QCoreApplication::translate("MainWindow", "10m", nullptr));
        btnPreset15->setText(QCoreApplication::translate("MainWindow", "15m", nullptr));
        btnPreset30->setText(QCoreApplication::translate("MainWindow", "30m", nullptr));
        btnStartTimer->setText(QCoreApplication::translate("MainWindow", "\342\226\266  Start", nullptr));
        btnResetTimer->setText(QCoreApplication::translate("MainWindow", "\342\206\272  Reset", nullptr));
        tabAturWaktu->setTabText(tabAturWaktu->indexOf(tabTimer), QCoreApplication::translate("MainWindow", "Timer", nullptr));
        labelSWHeader->setText(QCoreApplication::translate("MainWindow", "STOPWATCH", nullptr));
        labelStopwatch->setText(QCoreApplication::translate("MainWindow", "00:00.00", nullptr));
        btnStartSW->setText(QCoreApplication::translate("MainWindow", "\342\226\266  Start", nullptr));
        btnLapSW->setText(QCoreApplication::translate("MainWindow", "\342\232\221  Lap", nullptr));
        btnResetSW->setText(QCoreApplication::translate("MainWindow", "\342\206\272  Reset", nullptr));
        listLap->setStyleSheet(QCoreApplication::translate("MainWindow", "QListWidget { background-color: #ffffff; border: 1.5px solid #e0ddf0; border-radius: 12px; padding: 6px; font-family: 'Inter'; font-size: 13px; color: #14121e; } QListWidget::item { padding: 6px 10px; border-radius: 8px; margin: 2px 0px; } QListWidget::item:selected { background-color: #fff0f6; color: #fa73a6; }", nullptr));
        tabAturWaktu->setTabText(tabAturWaktu->indexOf(tabStopwatch), QCoreApplication::translate("MainWindow", "Stopwatch", nullptr));
        menubar->setStyleSheet(QCoreApplication::translate("MainWindow", "QMenuBar { background-color: #f8f7fc; color: #14121e; font-family: 'Inter'; font-size: 13px; } QMenuBar::item:selected { background-color: #ede9f8; border-radius: 6px; }", nullptr));
        statusbar->setStyleSheet(QCoreApplication::translate("MainWindow", "QStatusBar { background-color: #f8f7fc; color: #a09eaa; font-family: 'Inter'; font-size: 12px; }", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
