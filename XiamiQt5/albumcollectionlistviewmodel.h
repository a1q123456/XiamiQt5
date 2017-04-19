#ifndef ALBUMCOLLECTIONLISTVIEWMODEL_H
#define ALBUMCOLLECTIONLISTVIEWMODEL_H


class AlbumCollectionListViewModel
{
public:

    AlbumCollectionListViewModel(const uint64_t & albumId, const QString& picPath, const QString& albumName);

    uint64_t albumId;
    QString picPath;
    QString albumName;
};

#endif // ALBUMCOLLECTIONLISTVIEWMODEL_H
