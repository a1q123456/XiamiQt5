#include "pch.h"
#include <xiamiapi.h>
#include <QMediaPlayer>
#include <QMediaPlaylist>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    is_maxiumized = false;
    is_moving = false;
    api = xiamiapi::IXiamiAPI::CreateInstance();
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    QGraphicsDropShadowEffect *wndShadow = new QGraphicsDropShadowEffect;
    wndShadow->setBlurRadius(9.0);
    wndShadow->setColor(QColor(0, 0, 0, 160));
    wndShadow->setOffset(0);
    ui->setupUi(this);
    ui->centralWidget->setGraphicsEffect(wndShadow);
    FunctionListModel * model = new FunctionListModel(this);
    player = new QMediaPlayer;
    ui->player_duration_slider->setMinimum(0);
    qplaylist = new QMediaPlaylist(this);
    playlistmodel = new PlaylistTableModel(this, 0);
    playhistorymodel = new PlayhistoryTableModel(this);
    connect(player, &QMediaPlayer::durationChanged, [this](qint64 duration){
        player_current_duration.str("");
        qint64 minute = duration/60000;
        if (minute < 10) player_current_duration << "0";
        player_current_duration << minute;
        player_current_duration << ":";
        int second = (duration%60000) / 1000;
        if (second < 10) player_current_duration << "0";
        player_current_duration << second;
        ui->player_duration_label->setText(player_current_duration.str().c_str());
        ui->player_duration_slider->setMaximum(duration);
        int idx = qplaylist->currentIndex();
        const SongInfo & song_info = playlistmodel->getSong(idx);
        emit onSongChanged(idx, song_info);
        playlistmodel->setPlayed(idx);
        playhistorymodel->add(song_info);
    });
    connect(player, &QMediaPlayer::positionChanged, [this](qint64 position) {
        player_current_position.str("");
        qint64 minute = position / 60000;
        if (minute < 10) player_current_position << "0";
        player_current_position << minute;
        player_current_position << ":";
        int second = (position%60000) / 1000;
        if (second < 10) player_current_position << "0";
        player_current_position << second;
        ui->player_position_label->setText(player_current_position.str().c_str());
        if (!player_seek_locker) ui->player_duration_slider->setValue(position);

    });
    connect(ui->player_duration_slider, &QSlider::sliderPressed, [&]() {
        player_seek_locker = true;
    });
    connect(ui->player_duration_slider, &QSlider::sliderReleased, [&]() {
        player_seek_locker = false;
        if (player_seeked) player->setPosition(ui->player_duration_slider->value());
        player_seeked = false;
    });
    connect(ui->player_duration_slider, &QSlider::sliderMoved, [&]() {
        player_seeked = true;
    });
    connect(ui->play_btn, &QCheckBox::clicked, [&]() {
        if (player->state() == QMediaPlayer::PlayingState)
        {
            player->pause();
        }
        else if (player->state() == QMediaPlayer::PausedState)
        {
            player->play();
        }
    });
    connect(player, &QMediaPlayer::stateChanged, [&](QMediaPlayer::State newState) {
        if (newState == QMediaPlayer::StoppedState)
        {
            ui->play_btn->setChecked(false);
            ui->play_btn->setCheckable(false);
        }
        else
        {
            ui->play_btn->setCheckable(true);
        }
        if (newState == QMediaPlayer::PlayingState)
        {
            ui->play_btn->setChecked(true);
        }
    });
    connect(ui->prev_btn, &QPushButton::clicked, [this]() {
        this->playPrev();
    });
    connect(ui->next_btn, &QPushButton::clicked, [this]() {
        this->playNext();
    });
    ui->function_list->setModel(model);
    ui->function_list->setCurrentIndex(model->index(0, 0));

    FunctionList::instance()->change_page(0, ui->main_content, this);
}
void MainWindow::on_function_list_clicked(const QModelIndex &index)
{
    FunctionList::instance()->change_page(index.row(), ui->main_content, this);
}

void MainWindow::play(QVector<SongInfo> && playlist)
{
    emit onPlaylistChanged();
    player->stop();
    playlistmodel->setSongs(std::move(playlist));
    qplaylist->clear();
    playlistmodel->playlist(qplaylist);
    player->setPlaylist(qplaylist);
    player->setVolume(50);

    player->play();
}

void MainWindow::playIndex(int idx)
{
    qplaylist->setCurrentIndex(idx);
}

void MainWindow::playNext()
{
    qplaylist->setCurrentIndex(qplaylist->currentIndex() + 1);
}

void MainWindow::playPrev()
{
    qplaylist->setCurrentIndex(qplaylist->currentIndex() - 1);
}

PlayhistoryTableModel *MainWindow::getPlayhistoryModelCopy(QWidget *parent) const
{
    auto ret = new PlayhistoryTableModel(parent);
    ret->setSongs(QVector<SongInfo>(playhistorymodel->getData()));
    return ret;
}

PlaylistTableModel * MainWindow::getPlaylistModelCopy(QWidget* parent) const
{
    auto ret = new PlaylistTableModel(parent, playlistmodel->getCurrentIndex());
    ret->setSongs(QVector<SongInfo>(playlistmodel->getData()));
    return ret;
}

MainWindow::~MainWindow()
{
    delete ui;
    xiamiapi::IXiamiAPI::DestroyInstance(api);
    delete player;
}

void MainWindow::on_close_btn_clicked()
{
    this->close();
}

void MainWindow::on_maxium_btn_clicked()
{
    if (is_maxiumized)
    {
        this->showNormal();
        is_maxiumized = false;
    }
    else
    {
        this->showMaximized();
        is_maxiumized = true;
    }
}

void MainWindow::on_minium_btn_clicked()
{
    this->showMinimized();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mouse_press_x_coord = event->x();
    mouse_press_y_coord = event->y();
    is_moving = true;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (!is_moving)
    {
        return;
    }
    move(event->globalX() - mouse_press_x_coord, event->globalY() - mouse_press_y_coord);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    is_moving = false;
}
