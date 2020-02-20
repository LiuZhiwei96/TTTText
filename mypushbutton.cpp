#include "mypushbutton.h"
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

MyPushButton::MyPushButton(QString normalPic)
{
    normalPicPath = normalPic;

    QPixmap pix;
    bool ret = pix.load(normalPic);

    if(!ret)
    {
        qDebug()<<"图片未读入";
        return;
    }

    setFixedSize(pix.width(),pix.height());
    setStyleSheet("QPushButton{border:opx;}");//设置不规则图片的样式
    setIcon(pix);
    setIconSize(QSize(pix.width(),pix.height()));

}

void MyPushButton::down()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");

    animation->setDuration(250);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::bounce()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");

    animation->setDuration(250);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

