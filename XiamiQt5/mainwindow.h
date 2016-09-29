#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playlist.h"
#include "xiamiapi.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void play(const Playlist& list);
    xiamiapi::IXiamiAPI * api = nullptr;
protected slots:
    void on_close_btn_clicked();

    void on_maxium_btn_clicked();

    void on_minium_btn_clicked();

    void on_function_list_clicked(const QModelIndex &index);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *) override;
private:
    Ui::MainWindow *ui;
    bool is_maxiumized;
    bool is_moving;
    int mouse_press_x_coord;
    int mouse_press_y_coord;
    QMediaPlayer * player;
    QMediaPlaylist * playlist;
};

#endif // MAINWINDOW_H
