#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playlisttablemodel.h"
#include "xiamiapi.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <sstream>
#include "playhistorytablemodel.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void play(QVector<SongInfo> && list);
    void playIndex(int idx);
    xiamiapi::IXiamiAPI * api = nullptr;
    PlaylistTableModel * getPlaylistModelCopy(QWidget* parent) const;
    void playNext();
    void playPrev();
    PlayhistoryTableModel * getPlayhistoryModelCopy(QWidget* parent) const;
signals:
    void onPlaylistChanged();
    void onSongChanged(int, const SongInfo &);

protected slots:
    void on_close_btn_clicked();

    void on_maxium_btn_clicked();

    void on_minium_btn_clicked();

    void on_function_list_clicked(const QModelIndex &index);

protected:
    bool player_seek_locker = false;
    bool player_seeked = false;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *) override;
private:
    std::stringstream player_current_duration;
    std::stringstream player_current_position;
    Ui::MainWindow *ui;
    bool is_maxiumized;
    bool is_moving;
    int mouse_press_x_coord;
    int mouse_press_y_coord;
    QMediaPlayer * player;
    QMediaPlaylist * qplaylist;
    PlaylistTableModel * playlistmodel;
    PlayhistoryTableModel * playhistorymodel;
};

#endif // MAINWINDOW_H
