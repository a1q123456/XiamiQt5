#ifndef ALBUMCOLLECTIONLISTVIEWADAPTER_H
#define ALBUMCOLLECTIONLISTVIEWADAPTER_H
#include <QVariant>
#include <vector>

#include "albumcollectionlistviewmodel.h"
#include "listviewmodelrole.h"


class AlbumCollectionListViewAdapter : public QAbstractListModel
{
public:
    AlbumCollectionListViewAdapter(QObject *parent);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    virtual QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;
    QHash<int, QByteArray> role_names{
        {CollectionIdRole, "albumId"},
        {PicPathRole, "picPath"},
        {Qt::DisplayRole, "albumName"}
    };
    void setItem(std::vector<AlbumCollectionListViewModel>&& data);
private:
    std::vector<AlbumCollectionListViewModel> list_data;
};

#endif // ALBUMCOLLECTIONLISTVIEWADAPTER_H
