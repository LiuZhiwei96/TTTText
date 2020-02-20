#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(350,620);
    setWindowTitle("461！");
    setWindowIcon(QIcon(":/image/icon.jpg"));

    connect(ui->actionQuit,&QAction::triggered,[=](){
       this->close();
    });

    chooseLevel = new chooseLevelWindow;//创建选择关卡界面

    MyPushButton * startBtn = new MyPushButton(":/image/startButton.png");//创建开始游戏按钮
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);

    connect(startBtn,&MyPushButton::clicked,[=](){//点击开始游戏按钮时  跳到选择关卡界面
        startBtn->down();//按钮的弹起特效
        startBtn->bounce();

        QTimer::singleShot(250,this,[=](){//做250ms的延时  展示开始按钮的弹起特效
            this->hide();
            chooseLevel->setGeometry(this->geometry());
            chooseLevel->show();
        });
    });

    connect(chooseLevel,&chooseLevelWindow::back,[=](){//当检测到选择关卡界面的返回按钮按下 发出back（）信号时 返回主界面
        QTimer::singleShot(250,this,[=](){
        chooseLevel->hide();
        this->setGeometry(chooseLevel->geometry());
        this->show();
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)//绘制主场景的背景图
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/image/img_bg_level_3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
