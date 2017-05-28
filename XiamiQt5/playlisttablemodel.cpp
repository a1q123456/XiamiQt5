#include "playlisttablemodel.h"

PlaylistTableModel::PlaylistTableModel(QObject *parent, int current_index) : QAbstractTableModel(parent), current_index(current_index)
{
}

int PlaylistTableModel::rowCount(const QModelIndex &parent) const
{
    return _data.length();
}

int PlaylistTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant PlaylistTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("状态");
            case 1:
                return QString("歌曲名");
            case 2:
                return QString("艺术家");
            }
        }
    }
    return QVariant();
}


void PlaylistTableModel::setPlayed(int idx)
{
    SongInfo & v = _data[idx];
    v.is_played = true;
    auto orig_pos = createIndex(current_index, 0);
    emit dataChanged(orig_pos, orig_pos);
    current_index = idx;
    auto topleft = createIndex(idx, 0);
    emit dataChanged(topleft, topleft);
}

QVariant PlaylistTableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    switch (role)
    {
    case Qt::DisplayRole:
        switch (col) {
        case 0:
            return _data[row].is_played ? (current_index == row ? "正在播放" : "已播放") : "未播放";
        case 1:
            return _data[row].song_name;
        case 2:
            return _data[row].artists;
        }
        break;
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
    }

    return QVariant();
}

void PlaylistTableModel::playlist(QMediaPlaylist *qplaylist)
{
    qplaylist->addMedia(_url_data);
}

void PlaylistTableModel::setSongs(QVector<SongInfo>&& songs)
{
    _data = QVector<SongInfo>(std::move(songs));
    _url_data.clear();
    for (auto i : _data)
    {
        _url_data.append(QMediaContent(QUrl(i.song_url)));
    }
    emit layoutChanged();
}

SongInfo &PlaylistTableModel::getSong(int idx)
{
    return _data[idx];
}

int PlaylistTableModel::getCurrentIndex() const
{
    return current_index;
}

void PlaylistTableModel::clear()
{
    _data.clear();
}

QVector<SongInfo> & PlaylistTableModel::getData()
{
    return _data;
}
