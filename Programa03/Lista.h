//
// Created by ivan_ on 14/04/2021.
//

#ifndef PROGRAMA03_LISTA_H
#define PROGRAMA03_LISTA_H



#include <iostream>
#include <stdexcept>
#include <memory>
#include <fstream>

using namespace std;

template<typename T>
class Lista
{
private:
    class NodeLista
    {
    public:
        T data;
        shared_ptr<NodeLista> next;
        NodeLista(const T& elem, shared_ptr<NodeLista> n = nullptr) : data(elem), next(n){}
    };

    size_t listSize;
    shared_ptr<NodeLista> listFront;
    shared_ptr<NodeLista> listBack;

public:
    Lista()
    {
        listSize = 0;
        listFront = nullptr;
        listBack = nullptr;
    }

    ~Lista()
    {
        clear();
    }

    bool empty() const;
    size_t size() const;
    void push_front(const T& element);
    void push_back(const T& element);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& element);
    void erase(size_t position);
    void clear();
    void remove(const T& element);
    T& operator [] (size_t position);
    T& get(size_t position);
    int find(const T& element);
    void show();
    void load(const string &filename);
    void save(const string &filename);
};

template<typename T>
bool Lista<T>::empty() const
{
    return listSize == 0;
}

template<typename T>
size_t Lista<T>::size() const
{
    return listSize;
}

template<typename T>
void Lista<T>::push_front(const T& element)
{
    if (empty())
    {
        listFront = make_shared<NodeLista>(element);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodeLista> temp = make_shared<NodeLista>(element, listFront);
        listFront = temp;
    }

    ++listSize;
}

template<typename T>
void Lista<T>::push_back(const T& element)
{
    if (empty())
    {
        listFront = make_shared<NodeLista>(element);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodeLista> temp = make_shared<NodeLista>(element);
        listBack->next = temp;
        listBack = temp;
    }

    ++listSize;
}

template<typename T>
const T& Lista<T>::front() const
{
    if (empty())
    {
        throw runtime_error("trying front() from empty list");
    }

    return listFront->data;
}

template<typename T>
const T& Lista<T>::back() const
{
    if (empty())
    {
        throw runtime_error("trying back() from empty list");
    }

    return listBack->data;
}

template<typename T>
void Lista<T>::pop_front()
{
    if (empty())
    {
        throw runtime_error("trying pop_front() from empty list");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        listFront = listFront->next;
    }
    --listSize;
}

template<typename T>
void Lista<T>::pop_back()
{
    if (empty())
    {
        throw runtime_error("Trying pop_back() from empty list");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        shared_ptr<NodeLista> temp = listFront;
        while(temp->next != listBack)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        listBack = temp;
    }
    --listSize;
}

template<typename T>
void Lista<T>::insert(size_t position, const T& element)
{
    if (empty())
    {
        throw runtime_error("trying insert() on empty list");
    }
    else if (position > size())
    {
        throw range_error("trying insert() in non valid position");
    }
    else if (position == 0)
    {
        push_front(element);
    }
    else if (position == size())
    {
        push_back(element);
    }
    else
    {
        shared_ptr<NodeLista> temp = listFront;
        for (size_t i(0); i < position-1; ++i)
        {
            temp = temp->next;
        }
        shared_ptr<NodeLista> newNode = make_shared<NodeLista>(element, temp->next);
        temp->next = newNode;
        ++listSize;
    }
}

template<typename T>
void Lista<T>::erase(size_t position)
{
    if (empty())
    {
        throw runtime_error("trying erase() from empty list");
    }
    else if (position >= size())
    {
        throw range_error("trying erase() from non valid position");
    }
    else if (position == 0)
    {
        pop_front();
    }
    else if (position == size()-1)
    {
        pop_back();
    }
    else
    {
        shared_ptr<NodeLista> temp = listFront;
        for (size_t i(0); i < position-1; ++i)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        --listSize;
    }
}

template<typename T>
void Lista<T>::clear()
{
    while(!empty())
    {
        pop_front();
    }
}

template<typename T>
void Lista<T>::remove(const T& element)
{
    if (empty())
    {
        throw runtime_error("trying remove() from empty list");
    }
    else
    {
        T data;
        size_t i = 0;
        shared_ptr<NodeLista> temp = listFront;

        while (temp != nullptr)
        {
            data = temp->data;
            temp = temp->next;
            if (element == data)
            {
                erase(i);
                --i;
            }
            ++i;
        }
    }
}

template<typename T>
T& Lista<T>::operator[](size_t position)
{
    return get(position);
}

template<typename T>
void Lista<T>::load(const string &filename)
{
    fstream file;
    file.open(filename, ios::in);
    if(file.is_open())
    {
        this->clear();
        T data;
        while(file >> data)
        {
            this->push_back(data);
        }
        file.close();
    }
}

template <typename T>
void Lista<T>::save(const string &filename)
{
    fstream file;
    file.open(filename, ios::out);

    if(file.is_open())
    {
        for(size_t i(0); i<this->size(); i++)
        {
            file << get(i);
        }
        file.close();
    }
}

template<typename T>
int Lista<T>::find(const T &element) {
    for(size_t i(0); i<this->size();i++){
        if(get(i) == element){
            return i;
        }
    }
    return -1;
}

template<typename T>
void Lista<T>::show() {
    for(size_t i(0);i<size();i++){
        cout << "**********" << i+1 << "**********";
        cout << get(i) << endl;
    }
}

template<typename T>
T& Lista<T>::get(size_t position) {
    if (empty())
    {
        throw runtime_error("trying [] from empty list");
    }
    else if (position >= size())
    {
        throw range_error("trying [] in non valid position");
    }

    shared_ptr<NodeLista> temp = listFront;
    for (size_t i(0); i < position; ++i)
    {
        temp = temp->next;
    }
    return temp->data;
}

#endif //PROGRAMA03_LISTA_H
