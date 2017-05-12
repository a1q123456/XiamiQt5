#include "carousellistviewmodel.h"

CarouselCollectionListViewModel::CarouselCollectionListViewModel(QObject *parent):
    QAbstractListModel(parent)
{

}

int CarouselCollectionListViewModel::rowCount(const QModelIndex &) const
{
    return list_data.size();
}

int CarouselCollectionListViewModel::columnCount(const QModelIndex &) const
{
    return 1;
}

void CarouselCollectionListViewModel::setItem(std::vector<CarouselCollectionModelObject>&& data)
{
    this->list_data = std::move(data);
}

QVariant CarouselCollectionListViewModel::data(const QModelIndex &index, int role) const
{
    switch (role)
    {
    case CollectionIdRole:
        return static_cast<uint>(list_data[index.row()].collectionId);
    case Qt::DisplayRole:
        return list_data[index.row()].collectionName;
    case PicPathRole:
        return list_data[index.row()].picPath;
    }
    return QVariant();
}


QHash<int, QByteArray> CarouselCollectionListViewModel::roleNames() const
{
    return role_names;
}
