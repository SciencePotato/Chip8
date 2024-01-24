#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::vector<int> *displayP;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    void paintEvent(QPaintEvent *) {
        QPainter painter(this);
        std::vector<int> display = *displayP;

        for (int i = 0; i < display.size(); i ++) {
            if (display[i] == 1) {
                painter.drawRect((i % 64) * 10, (i / 64) * 10, 10, 10);
                // painter.fillRect(i, i, 10, 10, Qt::red);
            }
        }
    }
};
#endif // MAINWINDOW_H
