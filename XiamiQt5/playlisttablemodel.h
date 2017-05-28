#ifndef PLAYLISTTABLEMODEL_H
#define PLAYLISTTABLEMODEL_H
#include <QAbstractTableModel>
#include <QMediaPlaylist>
#include "songinfo.h"

class PlaylistTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    PlaylistTableModel(QObject *parent, int current_index);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void playlist(QMediaPlaylist * qplaylist);
    void setSongs(QVector<SongInfo>&& songs);
    void clear();
    QVector<SongInfo>& getData();
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void setPlayed(int idx);
    SongInfo& getSong(int idx);
    int getCurrentIndex() const;
private:
    int current_index = 0;
    QVector<SongInfo> _data;
    QList<QMediaContent> _url_data;
};

#endif // PLAYLISTTABLEMODEL_H
