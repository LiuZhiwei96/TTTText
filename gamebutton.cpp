#include "gamebutton.h"

GameButton::GameButton(QWidget *parent) : QPushButton(parent)
{

}

GameButton::GameButton(QString gamePic)
{
    QPixmap pix;
    isWin=false;
    bool ret=pix.load(gamePic);
    if (!ret)
    {
        qDebug()<<"游戏图片未载入";
    }

    setFixedSize(pix.width(),pix.height());
    setStyleSheet("QPushButton{border:opx;}");//设置不规则图片的样式
    setIcon(pix);
    setIconSize(QSize(pix.width(),pix.height()));

    timer1 = new QTimer;
    timer2 = new QTimer;

    connect(timer1,&QTimer::timeout,[=](){//收到定时器发出的timeout信号后 将图片翻转
        QPixmap pix;
        pix.load(":/image/MyPicture8");
        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:opx;}");
        setIcon(pix);
        setIconSize(QSize(pix.width(),pix.height()));

        timer1->stop();
    });

    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        pix.load(":/image/MyPicture1");
        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:opx;}");
        setIcon(pix);
        setIconSize(QSize(pix.width(),pix.height()));
        timer2->stop();
    });
}

void GameButton::changeFlag()//重置图片状态 同时开启定时器
{
    if(this->flag)
    {
        this->flag=false;
        timer1->start(150);
    }
    else
    {
        this->flag=true;
        timer2->start(150);
    }
}

void GameButton::mousePressEvent(QMouseEvent *e)//若游戏已经胜利 则点击按钮时不作出响应 反之则将控制权交回父类
{
    if(this->isWin)
        return;
    else
        QPushButton::mousePressEvent(e);
}
