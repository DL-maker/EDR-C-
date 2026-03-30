#pragma once
#include <iostream>
#include <list>
#include <string>

class Playlist {
private:
    std::list<std::string> songs;

public:
    auto addSong(std::string song);
    auto addSongAt(std::string song, int position);
    auto removeSongAt(int position);
    auto moveSong(int from, int to);
    auto display();
    int count();
};