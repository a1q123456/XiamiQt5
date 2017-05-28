#include "pch.h"
#include <QDebug>
#include <QQuickItem>
#include "mainwindow.h"
#include "playlisttablemodel.h"

main_page::main_page(QWidget *parent, QWidget * context) :
    QWidget(parent),
    ui(new Ui::main_page)
{
    ui->setupUi(parent);
    xiamiapi::IGenericArray *recommend_list;
    this->context = context;
    auto api = ((MainWindow *)(context))->api;
    api->GetRecommendCollection(&recommend_list);
    std::vector<CarouselCollectionModelObject> list_data;
    for (uint64_t i = 0; i < recommend_list->length(); ++i)
    {
        xiamiapi::IXiamiCollectionInfo* info;
        recommend_list->get_element(i)->QueryInterface(recommend_list->ElementIID(), (void **)&info);
        std::string logo = info->get_logo();
        // logo.replace(logo.rfind("_1"), 2, "_5");
        list_data.push_back(CarouselCollectionModelObject{info->get_list_id(), logo.c_str(), info->get_collect_name()});
        info->Release();
    }
    recommend_list->Release();
    QQuickView *view = new QQuickView();

    CarouselCollectionListViewModel * model = new CarouselCollectionListViewModel(parent);
    model->setItem(std::move(list_data));

    QQmlContext* ctxt = view->rootContext();
    ctxt->setContextProperty("collectionModel", model);

    api->GetRecommendPlaylist(&recommend_list);
    std::vector<CarouselCollectionModelObject> playlist_data;
    for (uint64_t i = 0; i < recommend_list->length(); ++i)
    {
        xiamiapi::IXiamiPlaylistInfo* info;
        recommend_list->get_element(i)->QueryInterface(recommend_list->ElementIID(), (void **)&info);
        std::string logo = info->get_album_logo();
        logo.replace(logo.rfind("_1"), 2, "_5");
        playlist_data.push_back(CarouselCollectionModelObject{info->get_album_id(), logo.c_str(), info->get_album_name()});
        info->Release();
    }
    CarouselCollectionListViewModel * album_model = new CarouselCollectionListViewModel(parent);
    album_model->setItem(std::move(playlist_data));
    ctxt->setContextProperty("albumModel", album_model);


    view->setSource(QUrl("qrc:/carousel.qml"));
    QWidget *container = QWidget::createWindowContainer(view, this);
    QObject *item = view->rootObject();
    connect(item, SIGNAL(albumClicked(int)), this, SLOT(playAlbum(int)));
    connect(item, SIGNAL(collectionClicked(int)), this, SLOT(playCollection(int)));
    ui->horizontalLayout->addWidget(container);
}

main_page::~main_page()
{
    delete ui;
}

void main_page::playCollection(int collectionId)
{
    xiamiapi::IGenericArray * list;
    auto api = ((MainWindow *)(context))->api;
    api->GetCollectionPlaylist(collectionId, &list);
    QVector<SongInfo> playlist;
    for (uint64_t i = 0; i < list->length(); ++i)
    {
        xiamiapi::IXiamiPlaylistInfo * info;
        list->get_element(i)->QueryInterface(list->ElementIID(), (void **)&info);
        playlist.append(SongInfo(info->get_song_id(), info->get_title(), info->get_artist(), info->get_location()));
        info->Release();
    }
    list->Release();
    ((MainWindow *)(context))->play(std::move(playlist));
}

void main_page::playAlbum(int albumId)
{
    xiamiapi::IGenericArray * list;
    auto api = ((MainWindow *)(context))->api;
    api->GetAlbumPlaylist(albumId, &list);
    QVector<SongInfo> playlist;
    auto length = list->length();
    for (uint64_t i = 0; i < length; ++i)
    {
        xiamiapi::IXiamiPlaylistInfo * info;
        list->get_element(i)->QueryInterface(list->ElementIID(), (void **)&info);
        playlist.append(SongInfo(info->get_song_id(), info->get_title(), info->get_artist(), info->get_location()));
        info->Release();
    }
    list->Release();
    ((MainWindow *)(context))->play(std::move(playlist));
}

void main_page::loadImage(QPushButton* &button, FileDownloader* downloader)
{
    QPixmap buttonImage;
    buttonImage.loadFromData(downloader->downloadedData());
    QIcon icon(buttonImage);
    button->setIcon(icon);
    downloader->deleteLater();
}
