//
// Created by ivan_ on 25/03/2021.
//

#ifndef PROGRAMA02_ARBOL_H
#define PROGRAMA02_ARBOL_H

#include <fstream>

using namespace std;

template <typename T>
class Arbol
{
private:
    class Nodo
    {
    public:
        T dato;
        Nodo * izq;
        Nodo * der;
        Nodo(T _dato, Nodo* _der, Nodo* _izq) :
                dato(_dato), der(_der), izq(_izq) {};
    } *raiz, * aux, * aux2, *padre;
    void borrar(Nodo *&);
    Nodo* buscarPadre(Nodo*&, T&);
    Nodo* buscar(Nodo *&, T&);
    void eliminarHoja(Nodo *&);
    void eliminarUnHijo(Nodo *&);
    void eliminarDosHijos(Nodo *&);
    void imprimir(Nodo *&, int, int);
    void agregar(Nodo *&, T);
    void imprimirIn(Nodo *&);
    void imprimirPost(Nodo *&);
    void imprimirPre(Nodo *&);
    void save(Nodo *&, fstream&);
    int altura(Nodo *&);
public:
    Arbol();
    ~Arbol();
    void agregar(T);
    void imprimirIn();
    void imprimirPost();
    void imprimirPre();
    void eliminar(T);
    void imprimir();
    T& buscar(T dato);
    void load(string filename);
    void save(string filename);
    void borrar();
};


#endif //PROGRAMA02_ARBOL_H
