#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QPushButton>
#include <QDebug>
#include <QTimer>

class GameButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GameButton(QWidget *parent = 0);

    GameButton(QString gamePic);

    void changeFlag();
    void mousePressEvent(QMouseEvent *e);

    QTimer * timer1;
    QTimer * timer2;

    int posX;
    int posY;
    bool flag;
    bool isWin;



signals:

public slots:
};

#endif // GAMEBUTTON_H
