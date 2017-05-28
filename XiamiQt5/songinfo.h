#ifndef SONGINFO_H
#define SONGINFO_H
#include <QString>

class SongInfo
{
public:
    SongInfo();
    SongInfo(const uint64_t & song_id, const char * song_name, const char * artists, const char * song_url);

    uint64_t song_id;
    QString song_name;
    QString artists;
    QString song_url;
    bool is_played;
};

#endif // SONGINFO_H
