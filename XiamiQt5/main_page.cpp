#include "pch.h"

main_page::main_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::main_page)
{
    ui->setupUi(parent);
    xiamiapi::IGenericArray *recommend_list;
    auto api = xiamiapi::IXiamiAPI::CreateInstance();
    api->GetRecommendCollection(&recommend_list);
    std::vector<CarouselListModelObject> list_data;
    for (uint64_t i = 0; i < recommend_list->length(); ++i)
    {
        xiamiapi::IXiamiCollectionInfo* info;
        recommend_list->get_element(i)->QueryInterface(recommend_list->ElementIID(), (void **)&info);
        std::string logo = info->get_logo();
        logo.replace(logo.rfind("_1"), 2, "_5");
        list_data.push_back(CarouselListModelObject{info->get_list_id(), logo.c_str(), info->get_collect_name()});

    }
    QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    QQmlContext* ctxt = view->rootContext();
    CarouselListViewModel * model = new CarouselListViewModel(nullptr);
    model->setItem(list_data);
    ctxt->setContextProperty("albumModel", model);
    view->setSource(QUrl("qrc:/carousel.qml"));
    ui->horizontalLayout->addWidget(container);

}

main_page::~main_page()
{
    delete ui;
}

void main_page::loadImage(QPushButton* &button, FileDownloader* downloader)
{
    QPixmap buttonImage;
    buttonImage.loadFromData(downloader->downloadedData());
    QIcon icon(buttonImage);
    button->setIcon(icon);
    downloader->deleteLater();
}
