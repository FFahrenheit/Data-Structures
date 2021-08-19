//
// Created by ivan_ on 14/04/2021.
//

#ifndef PROGRAMA03_ARISTA_H
#define PROGRAMA03_ARISTA_H

#include "Vertice.h"

template <typename T> class Vertice;

template <typename T>
class Arista {
public:
    Arista(Vertice<T> * _destino, int _costo){
        destino = _destino;
        costo = _costo;
    }

    Arista(Vertice<T> * _destino){
        destino = _destino;
    }
    Vertice<T> * destino;
    int costo;

    bool operator==(const Arista &rhs) const;

    bool operator!=(const Arista &rhs) const;

    T& getDato();
};

template<typename T>
T &Arista<T>::getDato() {
    return destino->getDato();
}

template<typename T>
bool Arista<T>::operator==(const Arista &rhs) const {
    return *destino == *rhs.destino;
}

template<typename T>
bool Arista<T>::operator!=(const Arista &rhs) const {
    return !(rhs == *this);
}

#endif //PROGRAMA03_ARISTA_H
