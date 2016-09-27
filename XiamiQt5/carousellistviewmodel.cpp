#include "carousellistviewmodel.h"

CarouselListViewModel::CarouselListViewModel(QObject *parent):
    QAbstractListModel(parent)
{
}

int CarouselListViewModel::rowCount(const QModelIndex &) const
{
    return list_data.size();
}

int CarouselListViewModel::columnCount(const QModelIndex &) const
{
    return 1;
}

void CarouselListViewModel::setItem(const std::vector<CarouselListModelObject>& data)
{
    this->list_data = std::move(data);
}

QVariant CarouselListViewModel::data(const QModelIndex &index, int role) const
{
    switch (role)
    {
    case AlbumIdRole:
        return static_cast<uint>(list_data[index.row()].albumId);
    case Qt::DisplayRole:
        return list_data[index.row()].albumName;
    case PicPathRole:
        return list_data[index.row()].picPath;
    }
    return QVariant();
}

QHash<int, QByteArray> CarouselListViewModel::roleNames() const
{
    return role_names;
}
