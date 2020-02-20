#ifndef CHOOSELEVELWINDOW_H
#define CHOOSELEVELWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "mypushbutton.h"
#include "gamesense.h"


namespace Ui {
class chooseLevelWindow;
}

class chooseLevelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit chooseLevelWindow(QWidget *parent = 0);
    ~chooseLevelWindow();

    MyPushButton * backBtn;

    void paintEvent(QPaintEvent *);

    //维护游戏场景的指针
    GameSense * game;

private:
    Ui::chooseLevelWindow *ui;

signals:
    void back();

};

#endif // CHOOSELEVELWINDOW_H
