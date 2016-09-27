#ifndef CAROUSELLISTVIEWMODEL_H
#define CAROUSELLISTVIEWMODEL_H

#include <QAbstractListModel>
#include <QVariant>
#include <vector>
#include "carousellistmodelobject.h"

enum CarouselListViewModelRole {
    AlbumIdRole = Qt::UserRole + 1,
    PicPathRole = Qt::UserRole + 2
};


class CarouselListViewModel : public QAbstractListModel
{
public:
    CarouselListViewModel(QObject *parent);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    virtual QHash<int, QByteArray> roleNames() const;
    QHash<int, QByteArray> role_names{
        {AlbumIdRole, "albumId"},
        {PicPathRole, "picPath"},
        {Qt::DisplayRole, "albumName"}
    };
    void setItem(const std::vector<CarouselListModelObject>& data);
private:
    std::vector<CarouselListModelObject> list_data;
};

#endif // CAROUSELLISTVIEWMODEL_H
