#include "gamesense.h"
#include "ui_gamesense.h"
#include "mypushbutton.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <QLabel>
#include <QPropertyAnimation>

GameSense::GameSense(int number) :
    ui(new Ui::GameSense)
{
    ui->setupUi(this);

//    qDebug()<<"打开了第"<<number<<"关";

    int index=number;//储存当前关卡号

    setFixedSize(350,620);
    setWindowTitle("461！");
    setWindowIcon(QIcon(":/image/icon.jpg"));

    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    MyPushButton * backBtn = new MyPushButton(":/image/back1.png");//游戏场景中的返回按钮
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    connect(backBtn,&MyPushButton::clicked,[=](){//点击返回按钮后 经过300ms的延时 发出back信号
        backBtn->down();
        backBtn->bounce();
        QTimer::singleShot(300,[=](){
            emit back();
        });
    });


    QLabel * label = new QLabel;//显示当前关卡为第几关
    label->setParent(this);
    QFont font;
    font.setFamily("微软雅黑");
    font.setPointSize(20);
    font.setBold(true);
    label->setFont(font);
    QString str=QString("Level %1").arg(index);
    label->setText(str);
    label->move(30,320);
    label->setAttribute(Qt::WA_TransparentForMouseEvents);//51号  鼠标穿透属性

    dataconfig config;//游戏内部具体场景的实现
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            gameArray[i][j]=config.mData[index][i][j];//将datadialog中的数据导入gameArray中
        }
    }

    isWin = false;//将游戏胜利标志初始化为fasle

    QLabel * winLabel = new QLabel;//创建游戏胜利的图片并将其隐藏
    winLabel->setParent(this);
    QPixmap pix;
    pix.load(":/image/victory.png");
    winLabel->setFixedSize(pix.width(),pix.height());
    winLabel->setPixmap(pix);
    winLabel->move(this->width()*0.5-winLabel->width()*0.5,-winLabel->height());


    QString str1;
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            if(gameArray[i][j]==1)
                str1=QString(":/image/MyPicture1.png");
            else
                str1=QString(":/image/MyPicture8.png");

            GameButton * gameBtn = new GameButton(str1);//创建出游戏按钮
            button[i][j]=gameBtn;//将新创建出的游戏按钮储存至二维指针数组中
            gameBtn->posX=i;//记录游戏按钮的相关信息
            gameBtn->posY=j;
            gameBtn->flag=gameArray[i][j];
            gameBtn->setParent(this);
            gameBtn->move(30+i*80,150+j*80);

            connect(gameBtn,&GameButton::clicked,[=](){//按下一个按钮时 改变游戏数组中该按钮的状态 该按钮图片翻转 同时与其相邻的图片均翻转
                gameArray[i][j]=gameArray[i][j]==1?0:1;
                gameBtn->changeFlag();

                if(gameBtn->posX<3)
                {
                    gameArray[gameBtn->posX+1][gameBtn->posY]=gameArray[gameBtn->posX+1][gameBtn->posY]==1?0:1;
                    button[gameBtn->posX+1][gameBtn->posY]->changeFlag();
                }
                if(gameBtn->posX>0)
                {
                    gameArray[gameBtn->posX-1][gameBtn->posY]=gameArray[gameBtn->posX-1][gameBtn->posY]==1?0:1;
                    button[gameBtn->posX-1][gameBtn->posY]->changeFlag();
                }

                if(gameBtn->posY<3)
                {
                    gameArray[gameBtn->posX][gameBtn->posY+1]=gameArray[gameBtn->posX][gameBtn->posY+1]==1?0:1;
                    button[gameBtn->posX][gameBtn->posY+1]->changeFlag();
                }

                if(gameBtn->posY>0)
                {
                    gameArray[gameBtn->posX][gameBtn->posY-1]=gameArray[gameBtn->posX][gameBtn->posY-1]==1?0:1;
                    button[gameBtn->posX][gameBtn->posY-1]->changeFlag();
                }


                isWin = true;

                for(int i = 0;i<4;i++)//检查每个按钮的状态  若仍有状态为0的按钮   则将胜利标志置为false
                {
                    for(int j = 0;j<4;j++)
                    {
                        if(gameArray[i][j]==0)
                        {
                            isWin=false;
                            break;
                        }
                    }
                }

                if(isWin)
                {
                    for(int i = 0;i<4;i++)//若游戏胜利 将每个按钮中的胜利标志设置为true 胜利后再点击按钮时 按钮不作出反应
                    {
                        for(int j = 0;j<4;j++)
                        {
                            button[i][j]->isWin=true;
                        }
                    }
                    QPropertyAnimation * animation = new QPropertyAnimation(winLabel,"geometry");//游戏胜利 显示游戏胜利图片
                    animation->setDuration(1000);
                    animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                    animation->setEndValue(QRect(winLabel->x(),winLabel->y()+180,winLabel->width(),winLabel->height()));
                    animation->setEasingCurve(QEasingCurve::OutBounce);
                    animation->start();
                }
            });
        }
    }



}

GameSense::~GameSense()
{
    delete ui;
}




void GameSense::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/mainBackground.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
