#include "playhistorytablemodel.h"

PlayhistoryTableModel::PlayhistoryTableModel(QObject *parent) : QAbstractTableModel(parent)
{
}

int PlayhistoryTableModel::rowCount(const QModelIndex &parent) const
{
    return _data.length();
}

int PlayhistoryTableModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant PlayhistoryTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("歌曲名");
            case 1:
                return QString("艺术家");
            }
        }
    }
    return QVariant();
}


QVariant PlayhistoryTableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    switch (role)
    {
    case Qt::DisplayRole:
        switch (col) {
        case 0:
            return _data[_data.length() - row - 1].song_name;
        case 1:
            return _data[_data.length() - row - 1].artists;
        }
        break;
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
    }

    return QVariant();
}

void PlayhistoryTableModel::playlist(QMediaPlaylist *qplaylist)
{
    qplaylist->addMedia(_url_data);
}

void PlayhistoryTableModel::add(const SongInfo &info)
{
    _data.append(SongInfo(info));
    emit layoutChanged();
}

void PlayhistoryTableModel::setSongs(QVector<SongInfo> &&songs)
{
    _data = std::move(songs);
    emit layoutChanged();
}

void PlayhistoryTableModel::clear()
{
    _data.clear();
}

QVector<SongInfo> & PlayhistoryTableModel::getData()
{
    return _data;
}
