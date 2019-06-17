#ifndef SHARE_H
#define SHARE_H
#include<QUdpSocket>
#include<QPixmap>
#include<QThread>
#include<QTime>
#include<QScreen>
#include<QGuiApplication>
#include<QApplication>
#include<QDesktopWidget>
#include<QDataStream>
#include"sharepackage.h"
#include<sys/time.h>
#define PKG_SIZE 1024

class Share : public QThread
{
public:
    Share();
    QUdpSocket *send;
    QTime *t;
    QScreen *screen;
    int package_size = 1024;
    void run();

signals:
    void sendScrrenToMainWindow(QImage image);
};

#endif // SHARE_H
