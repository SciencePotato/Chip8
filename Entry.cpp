#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include "Chip.cpp"

using namespace std;


int main(int argc, char *argv[]) {

    QApplication qApplication(argc, argv);

    Chip c;
    c.init();
    // c.execute();

    return QApplication::exec();
}