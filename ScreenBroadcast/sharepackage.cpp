#include "sharepackage.h"

SharePackage::SharePackage()
{

}

QDataStream& operator << (QDataStream& stream,SharePackage& pkg){
    QByteArray array;
    QDataStream out(&array,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);
    out<<pkg.index<<pkg.T<<pkg.pkgNum;
    stream<<array<<pkg.array;
    return stream;
}

