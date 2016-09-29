#include "songinfo.h"
#include <cstdint>

SongInfo::SongInfo()
{}

SongInfo::SongInfo(const uint64_t & song_id, const char * song_name, const char * artists, const char * song_url) :
    song_id(song_id),
    song_name(song_name),
    artists(artists),
    song_url(song_url)
{

}
