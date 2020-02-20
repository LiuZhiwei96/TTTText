#include "chooselevelwindow.h"
#include "ui_chooselevelwindow.h"
#include <QDebug>
#include <QLabel>
#include <QTimer>



chooseLevelWindow::chooseLevelWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chooseLevelWindow)
{
    ui->setupUi(this);

    setFixedSize(350,620);
    setWindowTitle("461！");
    setWindowIcon(QIcon(":/image/icon.jpg"));

    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    backBtn = new MyPushButton(":/image/back.png");//设置返回按钮的属性
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height()-20);

//    connect(backBtn,&MyPushButton::clicked,[=](){
//        qDebug()<<"123";
//    });

    connect(backBtn,&MyPushButton::clicked,[=](){//点击返回按钮时 chooseLevelWindow对象发出back()信号
        backBtn->down();
        backBtn->bounce();
        emit back();
    });

//    game = NULL;//先将指向游戏场景的指针设置为空


    QTimer * timer=new QTimer;

    for(int i=0;i<20;i++)
    {
        MyPushButton * chooseBtn = new MyPushButton(":/image/chooseButton.png");//设置选择关卡按钮
        chooseBtn->setParent(this);
        chooseBtn->move(25+(i%4)*80,65+(i/4)*80);

        QLabel * label = new QLabel(this);//设置选择关卡按钮上的数字及其属性
        QFont font;
        font.setFamily("微软雅黑");
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);
        label->setFixedSize(chooseBtn->width(),chooseBtn->height());
        label->move(25+(i%4)*80,80+(i/4)*80+4);
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);//51号  鼠标穿透属性

        connect(chooseBtn,&MyPushButton::clicked,[=](){//点击关卡按钮 进入相应的游戏界面

//            qDebug()<<"选择了第"<<i+1<<"关";

            chooseBtn->down();
            chooseBtn->bounce();
            timer->singleShot(250,this,[=](){
            game = new GameSense(i+1);
            game->setGeometry(this->geometry());
            connect(game,&GameSense::back,[=](){// 每次创建出来的游戏界面都是不同的  所以需要在new之后给具体的场景做信号与槽的连接
                 this->setGeometry(game->geometry());
                 game->close();
                 delete game;
                 this->show();
                });
            this->hide();
            game->show();
            });


        });

    }





}

chooseLevelWindow::~chooseLevelWindow()
{
    delete ui;
}

void chooseLevelWindow::paintEvent(QPaintEvent *)  //绘制关卡选择场景的背景图片
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/image/chooseLevel.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}


