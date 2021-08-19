//
// Created by ivan_ on 14/04/2021.
//

#ifndef PROGRAMA03_VERTICE_H
#define PROGRAMA03_VERTICE_H

#include <ostream>
#include "Lista.h"
#include "Arista.h"

template <typename T>
class Vertice {
private:
    T dato;    //Almacena el dato
    Lista<Arista<T>> aristas; //Contiene una lista de aristas hacia otros vertices
public:
    Vertice(T _dato){
        dato = _dato;
        aristas = Lista<Arista<T>>();
    }
    void mostrar();
    bool operator==(const Vertice &rhs) const;
    bool operator!=(const Vertice &rhs) const;
    string aristasLista();

    T& getDato();
    bool agregarArista(Vertice * destino,int costo);
    void borrarCoincidencias(Vertice * vertice);
    bool eliminarArista(Vertice * vertice);
};

template<typename T>
void Vertice<T>::mostrar() {
    cout << dato;
    for(size_t i(0);i<aristas.size();i++){
        Arista<T> arista = aristas.get(i);
        T dato = arista.getDato();
        cout << "\t-> " << dato.getIdSuceso() << "( " << arista.costo << " F.U. ): "
                << dato.getDescripcion() << " (" << dato.getFecha() << ")" << endl;
    }
}

template<typename T>
bool Vertice<T>::operator==(const Vertice &rhs) const {
    return dato == rhs.dato;
}

template<typename T>
bool Vertice<T>::operator!=(const Vertice &rhs) const {
    return !(rhs == *this);
}

template<typename T>
T& Vertice<T>::getDato() {
    return dato;
}

template<typename T>
bool Vertice<T>::agregarArista(Vertice * destino, int costo) {
    int pos = aristas.find(destino);
    if(pos != -1){
        return false;
    }

    aristas.push_back(Arista<T>(destino,costo));
    return true;
}

template<typename T>
void Vertice<T>::borrarCoincidencias(Vertice * vertice) {
    int pos = aristas.find(Arista<T>(vertice));

    if(pos != -1){
        aristas.erase(pos);
    }
}

template<typename T>
bool Vertice<T>::eliminarArista(Vertice *vertice) {
    int pos = aristas.find(Arista<T>(vertice));

    if(pos==-1){
        return false;
    }

    aristas.erase(pos);
    return true;
}

template<typename T>
string Vertice<T>::aristasLista() {
    string out = "";
    for(size_t i(0);i < aristas.size();i++){
        out += to_string(dato.getIdSuceso());
        out += "|";
        out += to_string(aristas.get(i).getDato().getIdSuceso());
        out += "|";
        out += to_string(aristas.get(i).costo);
        out += "*";
    }
    return out;
}


#endif //PROGRAMA03_VERTICE_H
