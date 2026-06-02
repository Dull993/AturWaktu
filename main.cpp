#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
        //test comment
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QCoreApplication::exec();
}
