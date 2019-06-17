#include "sharepackage.h"

SharePackage::SharePackage()
{

}


QDataStream& operator >> (QDataStream& stream,SharePackage& pkg){
    QByteArray a,b;
    stream>>b>>a;
    pkg.array = a;
    QDataStream out(&b,QIODevice::ReadOnly);
    out.setVersion(QDataStream::Qt_5_2);
    out>>pkg.index>>pkg.pkgNum>>pkg.T;
    return stream;
}

