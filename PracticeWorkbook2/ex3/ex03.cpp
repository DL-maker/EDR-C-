#include <iostream>
#include "ex03.hpp"

auto Playlist::addSong(std::string song) {
    songs.push_back(song);
}

auto Playlist::addSongAt(std::string song, int position) {
    auto debut = songs.begin();
    std::advance(debut, position);
    songs.insert(debut, song);
}

auto Playlist::removeSongAt(int position) {
    auto debut= songs.begin();
    std::advance(debut, position);
    songs.erase(debut);
}

auto Playlist::moveSong(int depuis, int vers) {
    std::string song;
    int i = 0;
    for (std::string s : songs) {
        if (i == depuis) {
            song = s;
            break;
        }
        i++;
    }
    removeSongAt(depuis);
    addSongAt(song, vers);
}

auto Playlist::display() {
    std::cout << "=== Playlist ===" << '\n';
    int i = 1;
    for (std::string song : songs) {
        std::cout << i << ". " << song << '\n';
        i++;
    }
}

int Playlist::count() {
    return songs.size();
}

int main() {
    Playlist playlist;
    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");
    playlist.display();
    std::cout << "Total: " << playlist.count() << " songs" << '\n';

    playlist.addSongAt("New Song", 1);
    playlist.display();

    playlist.removeSongAt(2);
    playlist.display();

    playlist.moveSong(0, 2);
    playlist.display();

    return 0;
}