#include "mainwindow.h"
#include <QApplication>
#include <thread>
#include "Chip.cpp"

using namespace std;

class Main {
    Main() {

    }

    ~Main() = default;

    void run() {
        while (true) {

        }
    }
};

int main(int argc, char *argv[]) {

    QApplication qApplication(argc, argv);

    Chip c;
    c.init();
    // c.execute();

    return QApplication::exec();
}