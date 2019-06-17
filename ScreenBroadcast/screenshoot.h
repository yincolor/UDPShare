#ifndef SCREENSHOOT_H
#define SCREENSHOOT_H

#include<QBuffer>
#include<QPixmap>
#include<QImage>
#include<QScreen>
#include<QApplication>
#include<QDesktopWidget>
#include<QDebug>

class ScreenShoot
{
public:
    ScreenShoot();
    QImage map;
    QScreen *screen;
    QByteArray dataArray;
    QDataStream out;
    void getScreenShoot();

};

#endif // SCREENSHOOT_H
