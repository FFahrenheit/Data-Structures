//
// Created by ivan_ on 25/03/2021.
//

#ifndef PROGRAMA02_COTO_H
#define PROGRAMA02_COTO_H

#include <iostream>
#include "Arbol.h"
#include "Casa.h"

using namespace std;

class Coto {
private:
    Arbol<Casa> casas;
    string FILENAME = "file01.txt";
    void nuevaCasa();
public:
    Coto();
    void menu();
};


#endif //PROGRAMA02_COTO_H
