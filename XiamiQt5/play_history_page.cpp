#include "play_history_page.h"
#include "ui_play_history_page.h"
#include "mainwindow.h"

play_history_page::play_history_page(QWidget *parent, QWidget *context) :
    QWidget(parent),
    context(context),
    ui(new Ui::play_history_page)
{
    ui->setupUi(this);
    MainWindow* mainwindow = static_cast<MainWindow*>(context);
    ui->play_history_tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model = mainwindow->getPlayhistoryModelCopy(this);
    ui->play_history_tableview->setModel(model);
    song_changed_conn = connect(mainwindow, &MainWindow::onSongChanged, [mainwindow, this](int idx, const SongInfo & song) {
        model->add(song);
    });
}

play_history_page::~play_history_page()
{
    disconnect(song_changed_conn);
    delete ui;
}
