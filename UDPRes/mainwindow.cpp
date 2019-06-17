#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(sendByteArray(QByteArray&,bool)),this,SLOT(getByteArray(QByteArray&,bool)));
    this->rescive = new QUdpSocket();
    this->rescive->bind(9999,QUdpSocket::ShareAddress);
    qDebug()<<"正在监听广播地址....";
    connect(rescive,&QUdpSocket::readyRead,this,[=](){
        while(rescive->hasPendingDatagrams()){

            qDebug()<<"收到广播";
            QByteArray array;
            array.resize(rescive->pendingDatagramSize());
            this->rescive->readDatagram(array.data(),array.size());
            //qDebug()<<array;
            SharePackage p;
            QDataStream out(&array,QIODevice::ReadOnly);
            out.setVersion(QDataStream::Qt_5_2);
            out>>p;
            qDebug()<<p.index<<' '<<p.T<<' '<<p.pkgNum;
            if(p.index == p.pkgNum-1){
                emit sendByteArray(p.array,true);
                qDebug()<<"这是最后一个包";
            }
            else {
                emit sendByteArray(p.array,false);
            }
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::getByteArray(QByteArray &a, bool isLats){
    this->imageArray.append(a);
    if(isLats){
        qDebug()<<"做了某件事了，将要清空列表";
        QPixmap map;
        QDataStream o(&(this->imageArray),QIODevice::ReadOnly);
        o.setVersion(QDataStream::Qt_5_2);
        o>>map;
        ui->label->clear();
        //ui->label->setText(QString::number(this->imageArray.size()));
        ui->label->setPixmap(map);
        this->imageArray.clear();

    }
    else {
        qDebug()<<"马达马达!";
    }
}
