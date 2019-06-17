#ifndef RESIVE_H
#define RESIVE_H
#include<QThread>
#include<QByteArray>

class Resive : public QThread
{
public:
    Resive();
    void GetUDP();

signals:
    void onChange(QByteArray array);



};

#endif // RESIVE_H
