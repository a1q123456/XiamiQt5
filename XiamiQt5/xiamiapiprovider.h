#ifndef XIAMIAPIPROVIDER_H
#define XIAMIAPIPROVIDER_H

#include "icomponentprovider.h"
#include "xiamiapi.h"

class XiamiApiProvider : public IComponentProvider
{


public:
    XiamiApiProvider();
    virtual QWidget * Provide() = 0;
    virtual void Destroy(QWidget *) = 0;

    XiamiApiProvider(const XiamiApiProvider &)  = delete;
    XiamiApiProvider(XiamiApiProvider&&) = delete;
};

#endif // XIAMIAPIPROVIDER_H
