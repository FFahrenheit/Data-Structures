//
// Created by ivan_ on 10/03/2021.
//

#ifndef PROGRAMA01_SONG_H
#define PROGRAMA01_SONG_H

#include <iostream>

using namespace std;

class Song {
private:
    string name;
    string album;
    string artist;
public:
    Song();
    Song(const string &name, const string &album, const string &artist);

    friend ostream& operator <<(ostream& os, const Song& song);
    friend istream& operator >>(istream& is, Song& song);

    bool operator==(const Song &rhs) const;

    bool operator!=(const Song &rhs) const;

    const string &getName() const;
    void setName(const string &name);
    const string &getAlbum() const;
    void setAlbum(const string &album);
    const string &getArtist() const;
    void setArtist(const string &artist);

    void show();
};


#endif //PROGRAMA01_SONG_H
