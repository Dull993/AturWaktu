#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void updateWaktu();
    void updateTimer();
    void addAlarm();
    void checkAlarm();
    void deleteAlarm();

private:
    Ui::MainWindow *ui;


    QTimer *timer;
    bool isRunning   = false;
    int  detik       = 0;
    int  lapCount    = 0;

    // Timer
    QTimer *countdownTimer;
    bool isTimerRunning = false;
    int  sisaDetik      = 0;

    // Alarm
    QTimer *alarmTimer;
};

#endif // MAINWINDOW_H
