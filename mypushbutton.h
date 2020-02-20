#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QDebug>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);
    MyPushButton(QString normalPic);

    QString normalPicPath;
    QString pressPicPath;

    void down();
    void bounce();

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
