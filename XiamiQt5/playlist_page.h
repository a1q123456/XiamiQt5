#ifndef PLAYLIST_PAGE_H
#define PLAYLIST_PAGE_H

#include <QWidget>
#include "playlisttablemodel.h"

namespace Ui {
class playlist_page;
}

class playlist_page : public QWidget
{
    Q_OBJECT

public:
    explicit playlist_page(QWidget *parent = 0, QWidget * context = 0);
    ~playlist_page();

private:
    QWidget* context;
    PlaylistTableModel * model;
    Ui::playlist_page *ui;
    QMetaObject::Connection change_playlist_conn;
    QMetaObject::Connection change_state_conn;
};

#endif // PLAYLIST_PAGE_H
