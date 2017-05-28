#ifndef PLAY_HISTORY_H
#define PLAY_HISTORY_H

#include <QWidget>
#include "playhistorytablemodel.h"

namespace Ui {
class play_history_page;
}

class play_history_page : public QWidget
{
    Q_OBJECT

public:
    explicit play_history_page(QWidget *parent = 0, QWidget * context = 0);
    ~play_history_page();

private:
    Ui::play_history_page *ui;
    QWidget* context;
    PlayhistoryTableModel * model;
    QMetaObject::Connection song_changed_conn;
};

#endif // PLAY_HISTORY_H
