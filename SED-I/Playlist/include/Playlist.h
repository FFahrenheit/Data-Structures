#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include "Song.h"
#include "List.h"
#include "windows.h"
#include "algorithm"

using namespace std;

class Playlist
{
    public:
        Playlist();
        virtual ~Playlist();
    private:
        Song selected = Song(false);
        int cursor;
        int cont;
        int pkCount;
        bool asc;
        List<Song> songs;
        void printMenu();
        void gotoxy(int,int);
        bool isInteger(string);
        void printCursor();
        void printControls();
        int toInteger(string);
        int requestInt(string);
        string requestIntAsString(string);
};

#endif // PLAYLIST_H
