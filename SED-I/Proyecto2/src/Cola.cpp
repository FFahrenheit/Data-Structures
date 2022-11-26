#include "Cola.h"
#include "Pasajero.h"

using namespace std;

template <class T>
Cola<T>::Cola()
{
    fin = nullptr;
    frente = nullptr;
}

template <class T>
Cola<T>::~Cola()
{
    if(!vacia())
    {
        while(fin!=nullptr)
        {
            aux = fin->sig;
            delete(fin);
            fin = aux;
        }
    }
}

template <class T>
void Cola<T>::push(T dato)
{
    if(vacia())
    {
        frente = new Nodo(dato);
        frente->sig = nullptr;
        fin = frente;
    }
    else
    {
        aux = new Nodo(dato);
        aux->sig = fin;
        fin = aux;
    }
    //cout << "\n\n\t\tDato agregado correctamente" << endl;
}

template <class T>
void Cola<T>::pop()
{
    if(!vacia())
    {
        if(frente == fin)
        {
            aux = frente;
            frente = nullptr;
            fin = nullptr;
        }
        else
        {
            aux = fin;
            while(aux->sig != frente)
            {
                aux = aux->sig;
            }
            frente = aux;
            frente->sig = nullptr;
            aux = aux->sig;
        }
        delete(aux);
        //cout << "\n\n\t\tDato eliminado" << endl;
    }
    else
    {
        //cout << "\n\n\t\tLa cola ya esta vacia" << endl;
    }
}

template <class T>
T Cola<T>::getFin()
{
    if(!vacia())
    {
        return fin->dato;
    }
    else
    {
        return Pasajero();
        //cout << "\n\n\t\tLa cola esta vacia" << endl;
    }
}

template <class T>
T Cola<T>::getInicio()
{
    if(!vacia())
    {
        return frente->dato;
    }
    else
    {
        return Pasajero();
    }
}
template <class T>
bool Cola<T>::vacia()
{
    return frente == nullptr;
}

template class Cola<Pasajero>;
