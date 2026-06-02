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
    void updateWaktu();   // Stopwatch tick (10ms)
    void updateTimer();   // Timer countdown (1s)
    void addAlarm();
    void checkAlarm();
    void deleteAlarm();

private:
    Ui::MainWindow *ui;

    // Stopwatch
    QTimer *timer;
    bool isRunning   = false;
    int  detik       = 0;   // satuan 10ms (centisecond)
    int  lapCount    = 0;

    // Timer
    QTimer *countdownTimer;
    bool isTimerRunning = false;
    int  sisaDetik      = 0;

    // Alarm
    QTimer *alarmTimer;
};

#endif // MAINWINDOW_H
