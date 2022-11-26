#include "Song.h"

Song::Song(bool show)
{
}

Song::Song()
{
}

Song::~Song()
{
}

Song::Song(int i)
{
    gotoxy(90,13);
    cout << "Nueva cancion";
    id = i;
    newSong();
}

void Song::modify()
{
    gotoxy(90,13);
    cout << "Modificar cancion";
    newSong();
}

void Song::newSong()
{
    gotoxy(80,14);
    cout << "ID: " << id;
    gotoxy(80,15);
    cout << "Nombre: ";
    getline(cin,this->title);
    gotoxy(80,16);
    cout << "Artista: ";
    getline(cin,this->artist);
    gotoxy(80,17);
    cout << "Album: ";
    getline(cin,this->album);
    gotoxy(80,18);
    cout << "Tipo: ";
    getline(cin,this->genre);
}

int Song::getId() const
{
    return id;
}

string Song::getAlbum() const
{
    return album;
}

string Song::getTitle() const
{
    return title;
}

string Song::getArtist() const
{
    return artist;
}

string Song::getGenre() const
{
    return genre;
}

void Song::setId(int i)
{
    id = i;
}

void Song::setTitle(string t)
{
    title = t;
}

void Song::setAlbum(string a)
{
    album = a;
}

void Song::setArtist(string a)
{
    artist = a;
}

void Song::setGenre(string g)
{
    genre = g;
}

bool operator == (const Song &s1, const Song &s2)
{
    return s1.getId() == s2.getId();
}

bool operator > (const Song &s1, const Song &s2)
{
    //return s1.getId() > s2.getId();
    return s1.getTitle().compare(s2.getTitle()) > 0;
}

bool operator < (const Song &s1, const Song &s2)
{
    //return s1.getId() < s2.getId();
    return s1.getTitle().compare(s2.getTitle()) < 0;
}

bool operator <= (const Song &s1, const Song &s2)
{
    return s1.getTitle().compare(s2.getTitle()) <= 0;
}

bool operator >= (const Song &s1, const Song &s2)
{
    return s1.getTitle().compare(s2.getTitle()) >= 0;
}

bool operator != (const Song &s1, const Song &s2)
{
    return s1.getId() != s2.getId();
}

ostream& operator<<(ostream& os, const Song& s)
{
    os << s.getId();
    return os;
}

void Song::gotoxy(int x,int y)
{
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}




