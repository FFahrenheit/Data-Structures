#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <windows.h>

using namespace std;

template <class TIPO>
class List;

template <class TIPO>
class Node
{
    public:
        TIPO& getValue()
        {
            return value;
        }
        Node(TIPO& v, Node<TIPO> *pnext = nullptr, Node<TIPO> *pprev = nullptr) : value(v), ptrNext(pnext), ptrPrev(pprev) {}
    private:
        TIPO value;
        Node<TIPO> *ptrNext;
        Node<TIPO> *ptrPrev;
        friend class List<TIPO>; // funcion amiga que permite sobrecargar la lista
};

template <class TIPO>
class List
{ // objeto lista
    public:
        List() : ptrList(nullptr) {}
        ~List();
        void Add(TIPO v);
        void remove(TIPO& v);
        bool Empty() { return ptrList == nullptr; }
        void print();
        void ptrNext();
        void ptrPrev();
        void First();
        void Last();
        bool Current() { return ptrList != nullptr; }
        TIPO CurrentValue() { return ptrList->value; }
        TIPO& getAt(int);
        TIPO getMax();
        bool empty();
        void deleteFirst();
        void deleteLast();
        void deleteMax();
        void printInverse();
        void deleteAll();
        void gotoxy(int,int);
        void modifyAt(int);
    private:
        Node<TIPO> *ptrList; // puntero de la lista
};
#endif // LIST_H
