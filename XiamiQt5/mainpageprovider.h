#ifndef MAINPAGEPROVIDER_H
#define MAINPAGEPROVIDER_H

#include "icomponentprovider.h"
#include "main_page.h"

class MainPageProvider : public IComponentProvider
{
private:
    QWidget * parent;
    QWidget * context;

    MainPageProvider(const MainPageProvider &)  = delete;
    MainPageProvider(MainPageProvider&&) = delete;

public:
    MainPageProvider(QWidget *parent = 0, QWidget * context = 0);
    virtual QWidget * Provide() override;
    virtual void Destroy(QWidget * page) override;
    ~MainPageProvider();
};

#endif // MAINPAGEPROVIDER_H
