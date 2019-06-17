#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QUdpSocket>
#include<QPixmap>
#include<QImage>
#include<QDebug>

#include"sharepackage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void freshImage();
    QUdpSocket *rescive;
    QByteArray imageArray;

signals:
    void sendByteArray(QByteArray&,bool);

private slots:
    void getByteArray(QByteArray&,bool);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
