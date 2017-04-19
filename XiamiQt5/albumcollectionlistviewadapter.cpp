#include "albumcollectionlistviewadapter.h"

AlbumCollectionListViewAdapter::AlbumCollectionListViewAdapter(QObject *parent):
    QAbstractListModel(parent)
{
}

int AlbumCollectionListViewAdapter::rowCount(const QModelIndex &) const
{
    return list_data.size();
}

int AlbumCollectionListViewAdapter::columnCount(const QModelIndex &) const
{
    return 1;
}

void AlbumCollectionListViewAdapter::setItem(std::vector<AlbumCollectionListViewModel>&& data)
{
    this->list_data = std::move(data);
}

QVariant AlbumCollectionListViewAdapter::data(const QModelIndex &index, int role) const
{
    switch (role)
    {
    case CollectionIdRole:
        return static_cast<uint>(list_data[index.row()].albumId);
    case Qt::DisplayRole:
        return list_data[index.row()].albumName;
    case PicPathRole:
        return list_data[index.row()].picPath;
    }
    return QVariant();
}


QHash<int, QByteArray> AlbumCollectionListViewAdapter::roleNames() const
{
    return role_names;
}
