//
// Created by ivan_ on 10/03/2021.
//

#include "Song.h"

const string &Song::getName() const {
    return name;
}

void Song::setName(const string &name) {
    Song::name = name;
}

const string &Song::getAlbum() const {
    return album;
}

void Song::setAlbum(const string &album) {
    Song::album = album;
}

const string &Song::getArtist() const {
    return artist;
}

void Song::setArtist(const string &artist) {
    Song::artist = artist;
}

Song::Song() {}

Song::Song(const string &name, const string &album, const string &artist) : name(name), album(album), artist(artist) {}

ostream& operator <<(ostream& os, const Song& song)
{
    os << song.getName() << '|' << song.getAlbum()
        << '|' << song.getArtist() << '*';
    return os;
}

istream& operator >>(istream& is, Song& song)
{
    string aux;
    getline(is, aux, '|'); //Separador de campo

    if (!aux.empty())
    {
        song.setName(aux);
        getline(is, aux, '|'); //Separador de campo
        song.setAlbum(aux);
        getline(is, aux,'*'); //Separador de REGISTRO
        song.setArtist(aux);
    }
    return is;
}

bool Song::operator==(const Song &rhs) const {
    return name == rhs.name;
}

bool Song::operator!=(const Song &rhs) const {
    return !(rhs.name == this->name);
}

void Song::show() {
    cout << "Nombre: " << name << endl;
    cout << "Artista: " << artist << endl;
    cout << "Album: " << album << endl << endl;
}
