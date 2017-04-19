#include "xiamiapiprovider.h"

XiamiApiProvider::XiamiApiProvider()
{

}

void XiamiApiProvider::Destroy(QWidget * api)
{
    xiamiapi::IXiamiAPI::DestroyInstance(api);
}

QWidget *XiamiApiProvider::Provide()
{
    return xiamiapi::IXiamiAPI::CreateInstance();
}
