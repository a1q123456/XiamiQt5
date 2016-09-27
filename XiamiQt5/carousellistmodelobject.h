#ifndef CAROUSELLISTMODELOBJECT_H
#define CAROUSELLISTMODELOBJECT_H
#include <QString>

class CarouselListModelObject
{
public:
    CarouselListModelObject(const uint64_t & albumId, const QString& picPath, const QString& albumName);

    uint64_t albumId;
    QString picPath;
    QString albumName;
};

#endif // CAROUSELLISTMODELOBJECT_H
