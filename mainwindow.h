#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "chooselevelwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    chooseLevelWindow * chooseLevel;

    void paintEvent(QPaintEvent *);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
