#include "albumcollectionlistviewmodel.h"

AlbumCollectionListViewModel::AlbumCollectionListViewModel(const uint64_t &albumId, const QString &picPath, const QString &albumName)
    :
      albumId(albumId),
      picPath(picPath),
      albumName(albumName)
{}
