#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication qApplication(argc, argv);
    MainWindow w;
    w.setMaximumHeight(32);
    w.setMaximumWidth(64);
    w.show();

    return QApplication::exec();
}
