#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QWidget>
#include <memory>
#include "filedownloader.h"

namespace Ui {
class main_page;
}

class main_page : public QWidget
{
    Q_OBJECT

public:
    explicit main_page(QWidget *parent = 0);
    ~main_page();
private slots:
    void loadImage(QPushButton* &button, FileDownloader* downloader);
private:
    Ui::main_page *ui;
};

#endif // MAIN_PAGE_H
