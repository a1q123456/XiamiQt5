#ifndef IPAGE_H
#define IPAGE_H

#include <QWidget>

class IPageProvider
{
public:
    virtual QWidget * Provide() = 0;
    virtual void Destroy(QWidget *) = 0;
    virtual ~IPageProvider() {}
};

#endif // IPAGE_H
