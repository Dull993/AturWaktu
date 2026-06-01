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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QTabWidget *Alarm;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listAlarm;
    QTimeEdit *timeEditAlarm;
    QPushButton *btnAddAlarm;
    QPushButton *btnDeleteAlarm;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *labelStopwatch;
    QPushButton *btnStartSW;
    QPushButton *btnResetSW;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTimeEdit *timeEditTimer;
    QLabel *labelTimer;
    QPushButton *btnStartTimer;
    QPushButton *btnResetTimer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(829, 442);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Alarm = new QTabWidget(centralwidget);
        Alarm->setObjectName("Alarm");
        Alarm->setGeometry(QRect(310, 20, 282, 289));
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        listAlarm = new QListWidget(tab);
        listAlarm->setObjectName("listAlarm");

        verticalLayout_3->addWidget(listAlarm);

        timeEditAlarm = new QTimeEdit(tab);
        timeEditAlarm->setObjectName("timeEditAlarm");

        verticalLayout_3->addWidget(timeEditAlarm);

        btnAddAlarm = new QPushButton(tab);
        btnAddAlarm->setObjectName("btnAddAlarm");

        verticalLayout_3->addWidget(btnAddAlarm);

        btnDeleteAlarm = new QPushButton(tab);
        btnDeleteAlarm->setObjectName("btnDeleteAlarm");

        verticalLayout_3->addWidget(btnDeleteAlarm);

        Alarm->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 30, 221, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setMouseTracking(false);
        label->setAcceptDrops(false);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        labelStopwatch = new QLabel(verticalLayoutWidget);
        labelStopwatch->setObjectName("labelStopwatch");
        labelStopwatch->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelStopwatch);

        btnStartSW = new QPushButton(verticalLayoutWidget);
        btnStartSW->setObjectName("btnStartSW");

        verticalLayout->addWidget(btnStartSW);

        btnResetSW = new QPushButton(verticalLayoutWidget);
        btnResetSW->setObjectName("btnResetSW");

        verticalLayout->addWidget(btnResetSW);

        Alarm->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayoutWidget_2 = new QWidget(tab_3);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(40, 30, 201, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        timeEditTimer = new QTimeEdit(verticalLayoutWidget_2);
        timeEditTimer->setObjectName("timeEditTimer");
        timeEditTimer->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(timeEditTimer);

        labelTimer = new QLabel(verticalLayoutWidget_2);
        labelTimer->setObjectName("labelTimer");
        labelTimer->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(labelTimer);

        btnStartTimer = new QPushButton(verticalLayoutWidget_2);
        btnStartTimer->setObjectName("btnStartTimer");

        verticalLayout_2->addWidget(btnStartTimer);

        btnResetTimer = new QPushButton(verticalLayoutWidget_2);
        btnResetTimer->setObjectName("btnResetTimer");

        verticalLayout_2->addWidget(btnResetTimer);

        Alarm->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 829, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Alarm->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        timeEditAlarm->setDisplayFormat(QCoreApplication::translate("MainWindow", "HH:mm:ss", nullptr));
        btnAddAlarm->setText(QCoreApplication::translate("MainWindow", "Add Alarm", nullptr));
        btnDeleteAlarm->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        Alarm->setTabText(Alarm->indexOf(tab), QCoreApplication::translate("MainWindow", "Alarm", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "STOPWATCH", nullptr));
        labelStopwatch->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        btnStartSW->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        btnResetSW->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        Alarm->setTabText(Alarm->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Stopwatch", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TIMER", nullptr));
        timeEditTimer->setDisplayFormat(QCoreApplication::translate("MainWindow", "HH:mm:ss", nullptr));
        labelTimer->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        btnStartTimer->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        btnResetTimer->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        Alarm->setTabText(Alarm->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Timer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
