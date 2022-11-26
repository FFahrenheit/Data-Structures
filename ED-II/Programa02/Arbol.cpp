//
// Created by ivan_ on 25/03/2021.
//

#include <cmath>
#include <iomanip>
#include <iostream>

#include "Arbol.h"
#include "Utils.cpp"
#include "Casa.h"

using namespace std;

template<typename T>
Arbol<T>::Arbol()
{
    AjustarVentana(120,30);
    raiz = nullptr;
}

template<typename T>
Arbol<T>::~Arbol()
{
    borrar(raiz);
}

template<typename T>
void Arbol<T>::borrar(Nodo *& rama)
{
    if (rama)
    {
        borrar(rama->izq);
        borrar(rama->der);
        delete rama;
        rama = nullptr;
    }
}

template<typename T>
void Arbol<T>::agregar(Nodo *& rama, T dato)
{
    if(!rama)
    {
        rama = new Nodo(dato,nullptr,nullptr);
        cout << "El elemento se ha agregado" << endl;
    }
    else if(rama->dato == dato)
    {
        cout << "El elemento ya existe en el arbol" << endl;
    }
    else if(dato > rama->dato)
    {
        agregar(rama->der, dato);
    }
    else
    {
        agregar(rama->izq, dato);
    }
}

template<typename T>
void Arbol<T>::imprimirIn(Nodo *& rama)
{
    if(rama)
    {
        imprimirIn(rama->izq);
        cout << rama->dato << endl;
        imprimirIn(rama->der);
    }
}

template<typename T>
void Arbol<T>::imprimirPost(Nodo *& rama)
{
    if(rama)
    {
        imprimirPost(rama->izq);
        imprimirPost(rama->der);
        cout << rama->dato << endl;
    }
}

template<typename T>
void Arbol<T>::imprimirPre(Nodo *& rama)
{
    if(rama)
    {
        cout << rama->dato << endl;
        imprimirPre(rama->izq);
        imprimirPre(rama->der);
    }
}

template<typename T>
typename Arbol<T>::Nodo* Arbol<T>::buscar(Nodo *& rama, T& dato)
{
    if(!rama)
    {
        return nullptr;
    }
    if(rama->dato == dato)
    {
        return rama;
    }
    if(dato > rama->dato)
    {
        return buscar(rama->der,dato);
    }
    if(dato < rama->dato)
    {
        return buscar(rama->izq, dato);
    }
    return nullptr;
}

template<typename T>
void Arbol<T>::eliminar(T dato)
{
    aux2  = buscar(raiz,dato);
    if (aux2) //Si se encontro
    {
        if (!aux2->der && !aux2->izq)
        {
            eliminarHoja(aux2);
        }
        else if ((!aux2->der && aux2->izq)
                 || (!aux2->izq && aux2->der))
        {
            eliminarUnHijo(aux2);
        }
        else if (aux2->der && aux2->izq)
        {
            eliminarDosHijos(aux2);
        }
        cout << "Se ha suprimido la existencia del elemento" << endl;
    }
    else
    {
        cout << "No se ha encontrado el elemento" << endl;
    }
}

template<typename T>
void Arbol<T>::eliminarHoja(Nodo *& rama)
{
    padre = buscarPadre(raiz,rama->dato);
    if (padre)
    {
        (padre->izq == rama) ? padre->izq = nullptr : padre->der = nullptr;
        delete rama;
    }
    else
    {
        delete raiz;
        raiz = nullptr;
    }
}

template<typename T>
void Arbol<T>::eliminarUnHijo(Nodo *& rama)
{
    padre = buscarPadre(raiz, rama->dato);
    if (!padre)
    {
        (rama->der)? raiz = rama->der : raiz = rama->izq;
    }
    else
    {
        if (padre->izq == rama)
        {
            (!rama->izq) ? padre->izq = rama->der : padre->izq = rama->izq;
        }
        else
        {
            (!rama->izq) ? padre->der = rama->der : rama->der = rama->izq;
        }
    }
    delete rama;
}

template<typename T>
void Arbol<T>::eliminarDosHijos(Nodo *& rama)
{
    aux = rama->der;
    while (aux->izq)
    {
        aux = aux->izq;
    }
    padre = buscarPadre(raiz,aux->dato);
    rama->dato = aux->dato;
    if (aux != rama->der)
    {
        padre->izq = aux->der;
    }
    else
    {
        rama->der = aux->der;
    }
    delete aux;
}

template<typename T>
typename Arbol<T>::Nodo * Arbol<T>::buscarPadre(Nodo *& rama, T& dato)
{
    if (raiz == rama && rama->dato == dato)  //No hay padre, el es el padre
    {
        return nullptr;
    }
    if (rama->der && rama->dato < dato)
    {
        if (rama->der->dato == dato)
        {
            return rama;
        }
        else
        {
            return buscarPadre(rama->der,dato);
        }
    }
    else if (rama->izq && rama->dato > dato)
    {
        if (rama->izq->dato == dato)
        {
            return rama;
        }
        else
        {
            return buscarPadre(rama->izq,dato);
        }
    }
    return nullptr; //Para que compile, nunca se va a llamar en realidad
}

template <typename T>
int Arbol<T>::altura(Nodo *& rama) {
    if(rama == nullptr){
        return 0;
    }
    return max(altura(rama->izq),altura(rama->der)) + 1;
}

template <typename T>
void Arbol<T>::imprimir()
{
    system("cls");
    imprimir(raiz,0,0);
    gotoxy(0,altura(raiz) + 1);
}

template <typename T>
void Arbol<T>::imprimir(Nodo *& rama, int x0, int y0)
{
    if(rama)
    {
        double datos = pow(2,y0);  //Datos por nivel
        int y = y0;
        double margen = (120-(4*datos))/(datos+1);
        double xV =  (margen * (x0+1)) + x0*4 ;
        int x = round(xV);

        gotoxy(x,y);

        //cout << setw(4) << setfill(' ') << rama->dato;
        if(rama->izq){
            cout << char(218) << ' ';
        }
        cout << setw(4) << setfill(' ') << rama->dato.getNumero();
        if(rama->der){
            cout << ' ' << char(191);
        }

        imprimir(rama->izq,2*x0,y0+1);
        imprimir(rama->der,(2*x0)+1,y0+1);
    }
}

template <typename T>
void Arbol<T>::agregar(T dato)
{
    agregar(raiz,dato);
}

template <typename T>
void Arbol<T>::imprimirIn()
{
    imprimirIn(raiz);
}

template <typename T>
void Arbol<T>::imprimirPost()
{
    imprimirPost(raiz);
}

template <typename T>
void Arbol<T>::imprimirPre()
{
    imprimirPre(raiz);
}

template <typename T>
T& Arbol<T>::buscar(T dato)
{
    return buscar(raiz,dato)->dato;
}

template<typename T>
void Arbol<T>::save(Arbol::Nodo *& rama, fstream & file) {
    if(rama){
        file << rama->dato;
        save(rama->izq,file);
        save(rama->der,file);
    }
}

template<typename T>
void Arbol<T>::save(string filename) {
    fstream file;
    file.open(filename, ios::out);

    if(file.is_open()){
        this->save(raiz,file);
        file.close();
        cout << "Datos guardados" << endl;
    }
}

template<typename T>
void Arbol<T>::load(string filename) {
    fstream file;
    file.open(filename, ios::in);

    if(file.is_open()){
        this->borrar(raiz);
        T dato;
        while(file >> dato){
            this->agregar(dato);
        }
        file.close();
    }
}

template<typename T>
void Arbol<T>::borrar() {
    this->borrar(raiz);
}

template class Arbol<Casa>;
