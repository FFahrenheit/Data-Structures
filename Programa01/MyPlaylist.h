//
// Created by ivan_ on 10/03/2021.
//

#ifndef PROGRAMA01_MYPLAYLIST_H
#define PROGRAMA01_MYPLAYLIST_H

#include <iostream>
#include "LSL.h"
#include "Song.h"

class MyPlaylist {
private:
    LSL<Song> list;
    void addSong(size_t index);
    void searchSong();

public:
    MyPlaylist();
    ~MyPlaylist();
    void menu();
};


#endif //PROGRAMA01_MYPLAYLIST_H
