#include "ListaDoblementeEnlazada.h"

template <class TIPO>
List<TIPO>::~List() // Checked: Destructor de la clase
{
    Node<TIPO> *aux;
    First();
    while (ptrList)
    {
        aux = ptrList;
        ptrList = ptrList->ptrNext;
        delete aux;
    }
}

template <class TIPO>
void List<TIPO>::Add(TIPO v) // Checked: Agregar al Nodo
{
    Node<TIPO> *ptrNew;
    First(); // Metodo que permite insertar al inicio de la lista
    if (Empty() || ptrList->value > v)
    {
        ptrNew = new Node<TIPO>(v, ptrList);
        if (!ptrList)
        {
            ptrList = ptrNew;
        }
        else
        {
            ptrList->ptrPrev = ptrNew;
        }
    }
    else
    {
        // se mueve hasta el ultimo nodo que tenva un valor mayor
        while (ptrList->ptrNext && ptrList->ptrNext->value <= v)
        {
            ptrNext();
        }
        ptrNew = new Node<TIPO>(v, ptrList->ptrNext, ptrList);
        ptrList->ptrNext = ptrNew;
        if (ptrNew->ptrNext)
        {
            ptrNew->ptrNext->ptrPrev = ptrNew;
        }
    }
    cout << "Elemento agregado" << endl;;
}

template <class TIPO>
void List<TIPO>::remove(TIPO v)
{
    Node<TIPO> *ptrNode;
    First();
    ptrNode = ptrList;
    while (ptrNode && ptrNode->value < v)
    {
        ptrNode = ptrNode->ptrNext;
    }
    while (ptrNode && ptrNode->value > v)
    {
        ptrNode = ptrNode->ptrPrev;
    }
    if (!ptrNode || ptrNode->value != v) //No se encontro
    {
        cout << "No se encontro el elemento" << endl;
        return;
    }
    if (ptrNode->ptrPrev)// Si tiene anterior
    {
        ptrNode->ptrPrev->ptrNext = ptrNode->ptrNext;
    }
    if (ptrNode->ptrNext)// Si tiene siguiente
    {
        ptrNode->ptrNext->ptrPrev = ptrNode->ptrPrev;
    }
    cout << "Elemento eliminado" << endl;
    delete ptrNode;
}

template <class TIPO>
void List<TIPO>::print()
{
    Node<TIPO> *ptrNode;
    First();
    ptrNode = ptrList;
    while (ptrNode)
    {
        cout << ptrNode->value;
        if(ptrNode->ptrNext)
        {
            cout<< "->";
        }
        ptrNode = ptrNode->ptrNext;
    }
    cout << endl;
}

template <class TIPO>
void List<TIPO>::ptrNext()
{
    if (ptrList)
    {
        ptrList = ptrList->ptrNext;
    }
}

template <class TIPO>
void List<TIPO>::ptrPrev()
{
    if (ptrList)
    {
        ptrList = ptrList->ptrPrev;
    }
}

template <class TIPO>
void List<TIPO>::First()
{
    while (ptrList && ptrList->ptrPrev)
    {
        ptrList = ptrList->ptrPrev;
    }
}

template <class TIPO>
void List<TIPO>::Last()
{
    while (ptrList && ptrList->ptrNext)
    {
        ptrList = ptrList->ptrNext;
    }
}

template<class TIPO>
bool List<TIPO>::empty()
{
    First();
    return ptrList == nullptr;
}

template<class TIPO>
TIPO List<TIPO>::getMax()
{
    if(Empty())
    {
        return NULL;
    }
    First();
    TIPO max = ptrList->value;
    Node<TIPO> * aux = ptrList;
    while(aux != nullptr)
    {
        if(aux->value > max)
        {
            max = aux->value;
        }
        aux = aux->ptrNext;
    }
    return max;
}

template<class TIPO>
void List<TIPO>::deleteFirst()
{
    if(!Empty())
    {
        First();
        Node<TIPO> * aux = ptrList->ptrNext;
        if(aux)
        {
            aux->ptrPrev = nullptr;
        }
        delete ptrList;
        ptrList = aux;
    }
}

template<class TIPO>
void List<TIPO>::deleteLast()
{
    if(!Empty())
    {
        Last();
        Node<TIPO> * aux = ptrList->ptrPrev;
        if(aux)
        {
            aux->ptrNext = nullptr;
        }
        delete ptrList;
        ptrList = aux;
        First();
    }
}

template<class TIPO>
void List<TIPO>::deleteMax()
{
    if(!Empty())
    {
        TIPO max = getMax();
        First();
        while(ptrList->value != max)
        {
            ptrList = ptrList->ptrNext;
        }
        if(ptrList->ptrPrev)
        {
            ptrList->ptrPrev->ptrNext = ptrList->ptrNext;
        }
        if(ptrList->ptrNext)
        {
            ptrList->ptrNext->ptrPrev = ptrList->ptrPrev;
        }
        Node<TIPO> * aux = ptrList;
        First();
        delete aux;
    }
}

template<class TIPO>
void List<TIPO>::printInverse()
{
    Last();
    Node<TIPO> * aux = ptrList;
    while(aux != nullptr)
    {
        cout << aux ->value;
        if (aux->ptrPrev)
        {
            cout << " <- ";
        }
        aux = aux->ptrPrev;
    }
}

template<class TIPO>
void List<TIPO>::deleteAll()
{
    First();
    Node<TIPO> * aux = ptrList;
    Node<TIPO> * aux2;
    while(aux != nullptr)
    {
        aux2 = aux;
        aux = aux->ptrNext;
        delete aux2;
    }
    ptrList = nullptr;
}

template class List<int>;
