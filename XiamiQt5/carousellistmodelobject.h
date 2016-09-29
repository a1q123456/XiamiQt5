#ifndef CAROUSELLISTMODELOBJECT_H
#define CAROUSELLISTMODELOBJECT_H
#include <QString>

class CarouselCollectionModelObject
{
public:
    CarouselCollectionModelObject(const uint64_t & collectionId, const QString& picPath, const QString& collectionName);

    uint64_t collectionId;
    QString picPath;
    QString collectionName;
};

#endif // CAROUSELLISTMODELOBJECT_H
