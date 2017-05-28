#ifndef PLAYHISTORYTABLEMODEL_H
#define PLAYHISTORYTABLEMODEL_H
#include <QAbstractTableModel>
#include <QMediaPlaylist>
#include "songinfo.h"

class PlayhistoryTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    PlayhistoryTableModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void playlist(QMediaPlaylist * qplaylist);
    void add(const SongInfo& info);
    void setSongs(QVector<SongInfo>&& songs);
    void clear();
    QVector<SongInfo>& getData();
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void setPlayed(int idx);
private:
    int current_index = 0;
    QVector<SongInfo> _data;
    QList<QMediaContent> _url_data;
};

#endif // PLAYHISTORYTABLEMODEL_H
