#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <windows.h>

using namespace std;

class Song
{
    public:
        Song();
        Song(int);
        Song(bool);
        virtual ~Song();
        int getId() const;
        string getAlbum()const;
        string getTitle()const;
        string getArtist()const;
        string getGenre()const;
        void setId(int);
        void setTitle(string);
        void setAlbum(string);
        void setArtist(string);
        void setGenre(string);
        friend bool operator == (const Song &, const Song &);
        friend bool operator > (const Song &, const Song &);
        friend bool operator < (const Song &, const Song &);
        friend bool operator <= (const Song &, const Song &);
        friend bool operator >= (const Song &, const Song &);
        friend bool operator != (const Song &, const Song &);
        friend ostream& operator<<(ostream& os, const Song&);
        void gotoxy(int,int);
        void newSong();
        void modify();
    private:
        int id;
        string album;
        string title;
        string artist;
        string genre;
};

#endif // SONG_H
