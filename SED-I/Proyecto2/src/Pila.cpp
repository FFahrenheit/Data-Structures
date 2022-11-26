#include "Pila.h"
#include "Pasajero.h"

using namespace std;

template <class T>
Pila<T>::~Pila()
{
    if(!vacia())
    {
        while(tope!=nullptr)
        {
            aux = tope->sig;
            delete(tope);
            tope = aux;
        }
    }
}

template <class T>
Pila<T>::Pila()
{
    tope = nullptr;
}

template <class T>
void Pila<T>::push(T dato)
{
    if(vacia())
    {
        tope = new Nodo(dato);
        tope->sig = nullptr;
    }
    else
    {
        aux = new Nodo(dato);
        aux->sig = tope;
        tope = aux;
    }
    //cout << "\n\n\t\tDato agregado correctamente" << endl;
}

template <class T>
void Pila<T>::pop()
{
    if(!vacia())
    {
        aux = tope;
        tope = tope->sig;
        delete(aux);
        //cout << "\n\n\t\tDato eliminado" << endl;
    }
    else
    {
        //cout << "\n\n\t\tLa pila ya esta vacia" << endl;
    }
}

template <class T>
T Pila<T>::getTope()
{
    if(!vacia())
    {
        return tope->dato;
    }
    else
    {
        return Pasajero();
    }
}

template <class T>
bool Pila<T>::vacia()
{
    return tope == nullptr;
}

template class Pila<Pasajero>;
