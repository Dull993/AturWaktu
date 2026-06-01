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
    QTimer *countdownTimer;
    QTimer *alarmTimer;
    bool isTimerRunning = false;
    bool isRunning = false;
    int detik = 0;
    int sisaDetik = 0;
};

#endif // MAINWINDOW_H