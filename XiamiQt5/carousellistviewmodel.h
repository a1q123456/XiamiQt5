#ifndef CAROUSELLISTVIEWMODEL_H
#define CAROUSELLISTVIEWMODEL_H

#include <QAbstractListModel>
#include <QVariant>
#include <vector>
#include "carousellistmodelobject.h"

// #include "listviewmodelrole.h"
enum AlbumListViewModelRole {
    CollectionIdRole = Qt::UserRole + 1,
    PicPathRole = Qt::UserRole + 2
};


class CarouselCollectionListViewModel : public QAbstractListModel
{
public:
    CarouselCollectionListViewModel(QObject *parent);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    virtual QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;
    QHash<int, QByteArray> role_names{
        {CollectionIdRole, "collectionId"},
        {PicPathRole, "picPath"},
        {Qt::DisplayRole, "collectionName"}
    };
    void setItem(std::vector<CarouselCollectionModelObject>&& data);
private:
    std::vector<CarouselCollectionModelObject> list_data;
};

#endif // CAROUSELLISTVIEWMODEL_H
