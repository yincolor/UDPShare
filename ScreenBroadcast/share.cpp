#include "share.h"

Share::Share()
{
    this->screen = QGuiApplication::primaryScreen();
}

void Share::run(){
    this->t = new QTime();
    this->send = new QUdpSocket();
    char *str= "nihao";
    while (1) {
        qDebug()<<"循环广播,获取新的系统截屏";
        QByteArray array;
        qDebug()<<"创建输入流";
        QDataStream out(&array,QIODevice::ReadWrite);
        qDebug()<<"设置流版本";
        out.setVersion(QDataStream::Qt_5_2);
        qDebug()<<"截图并输入流中";
        //QImage image = this->screen->grabWindow(QApplication::desktop()->winId()).toImage();
        //uchar *bits = image.bits();
        //out.readBytes(image.bits(),image.byteCount());
        //out = QDataStream::readRawData(bits,1024);
        out<<this->screen->grabWindow(QApplication::desktop()->winId()).scaled(800,600,Qt::KeepAspectRatio);
        qDebug()<<"发送图片广播,图片大小："<<array.size()<<" Bytes. 需要分成"<<(array.size()/PKG_SIZE)+1<<"个包进行发送";
        for(int i=0;i<1+array.size()/PKG_SIZE;i++){
            SharePackage p;
            p.array = array.mid(i*PKG_SIZE,PKG_SIZE);
            p.index = i;
            p.T = 1+array.size()/PKG_SIZE;
            QByteArray array2;
            QDataStream out2(&array2,QIODevice::ReadWrite);
            out2.setVersion(QDataStream::Qt_5_2);
            out2<<p;
            this->send->writeDatagram(array2,QHostAddress::Broadcast,9999);
        }


        qDebug()<<"发送结束,休息1秒";
        sleep(0.05);
    }
}

void Share::sendScrrenToMainWindow(QImage image){

}


