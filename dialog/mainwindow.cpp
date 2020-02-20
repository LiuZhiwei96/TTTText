#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew,&QAction::triggered,[=](){

//        //创建模态对话框
//        QDialog dlg;
//        dlg.resize(160,40);
//        dlg.exec();    //阻塞功能，阻塞代码，时代码停止在这里，不继续向下运行。

//        //创建非模态对话框
//        QDialog * dlg2= new QDialog(this);
//        dlg2->resize(160,40);
//        dlg2->show();

        //用类名创建出来的对象是局部的，出了函数该对象就自动消失，
        //而在堆中new出来的对象赋给指针，指针需要释放才能够消失，所以在释放之前指针是一直存在的

//        dlg2->setAttribute(Qt::WA_DeleteOnClose);

//        //错误提示框
//        QMessageBox::critical(this,"错误","critical");

//        //信息提示框
//        QMessageBox::information(this,"信息","information");

//        //提问对话框
//        if(QMessageBox::Open==QMessageBox::question(this,"提问","ques",QMessageBox::Open | QMessageBox::Close, QMessageBox::Close))
//        {
//            qDebug()<<"按下的是open";
//        }
//        else
//            qDebug()<<"按下的是close";

        //文件对话框 参数一 父窗口 参数二 标题 参数三 默认打开路径 参数四 过滤后缀名
        QString filename= QFileDialog ::getOpenFileName(this,"打开文件","C:\\Users\\DELL\\Desktop");
        qDebug()<<"打开的文件是： "<<filename;


    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
