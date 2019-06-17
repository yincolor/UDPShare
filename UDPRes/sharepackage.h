#ifndef SHAREPACKAGE_H
#define SHAREPACKAGE_H
#include<QByteArray>
#include<QDataStream>
#include<sys/time.h>

class SharePackage
{
public:
    SharePackage();
    qint64 T;//时间戳，同分批次报文时间戳相同，时间戳也能允许程序识别哪个帧在前哪个帧在后
    qint64 index; //报文分包后的索引
    qint64 pkgNum;
    QByteArray array;
    friend QDataStream& operator >> (QDataStream&,SharePackage&);
};

#endif // SHAREPACKAGE_H
