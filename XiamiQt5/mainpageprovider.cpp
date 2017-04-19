#include "mainpageprovider.h"

MainPageProvider::MainPageProvider(QWidget *parent = 0, QWidget * context = 0)
{
    this->parent = parent;
    this->context = context;
}

QWidget *MainPageProvider::Provide()
{
    return new main_page(parent, context);
}

void MainPageProvider::Destroy(QWidget * page)
{
    delete page
}

MainPageProvider::~MainPageProvider()
{
}

