#include "playlist_page.h"
#include "ui_playlist_page.h"
#include "mainwindow.h"

playlist_page::playlist_page(QWidget *parent, QWidget* context) :
    QWidget(parent),
    ui(new Ui::playlist_page)
{
    ui->setupUi(this);
    this->context = context;
    MainWindow* mainwindow = static_cast<MainWindow*>(context);
    model = mainwindow->getPlaylistModelCopy(parent);
    ui->playlist_tableview->setModel(model);
    ui->playlist_tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    change_playlist_conn = connect(mainwindow, &MainWindow::onPlaylistChanged, [=]() {
        ui->playlist_tableview->setModel(mainwindow->getPlaylistModelCopy(parent));
    });
    change_state_conn = connect(mainwindow, &MainWindow::onSongChanged, [=](int idx, const SongInfo&) {

        model->setPlayed(idx);
        //ui->playlist_tableview->update();
    });
    connect(ui->playlist_tableview, &QTableView::doubleClicked, [this](const QModelIndex idx) {
        ((MainWindow *)this->context)->playIndex(idx.row());
    });
}

playlist_page::~playlist_page()
{
    disconnect(change_playlist_conn);
    disconnect(change_state_conn);
    delete ui;
}
