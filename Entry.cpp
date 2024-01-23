#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include "Chip.cpp"

using namespace std;
int main(int argc, char *argv[]) {
    Chip c;
    c.init();
    c.execute();

    // QT Frame
    QApplication qApplication(argc, argv);
    MainWindow window;
    window.setMaximumHeight(32);
    window.setMaximumWidth(64);
    window.show();

    return QApplication::exec();
}