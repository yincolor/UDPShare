#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QScreen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    ui->label->setPixmap(screen->grabWindow(QApplication::desktop()->winId()).scaled(800,600,Qt::KeepAspectRatio));

    qDebug()<<"新建udp线程";
    Share *share = new Share();
    qDebug()<<"开启udp线程";
    share->start();

}

MainWindow::~MainWindow()
{
    delete ui;

}
