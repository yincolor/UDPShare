#include "screenshoot.h"

ScreenShoot::ScreenShoot()
{
    this->screen = QGuiApplication::primaryScreen();
    out(&dataArray,QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_5_2);
}

void ScreenShoot::getScreenShoot(){
    this->map = this->screen->grabWindow(QApplication::desktop()->winId()).toImage();
}


