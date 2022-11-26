#include <iostream>
using namespace std;

template <typename T>
class CircularList
{
private:
    class Node
    {
    public:
        T number;
        Node *next;
        Node *back;
    };
    Node *ptrHead;

public:
    CircularList();
    ~CircularList();
    void insert_First(T);
    void insert_Last(T);
    bool empty();
    void print();
    int travel();
    void remove(int);
};

template <typename T>
CircularList<T>::CircularList()
{
    ptrHead = NULL;
}

template <typename T>
CircularList<T>::~CircularList()
{
    if (ptrHead != NULL)
    {
        Node *temp = ptrHead->next;
        Node *temp_ptrHead;
        while (temp != ptrHead)
        {
            temp_ptrHead = temp;
            temp = temp->next;
            delete temp_ptrHead;
        }
        delete ptrHead;
    }
}

template <typename T>
void CircularList<T>::insert_First(T number)
{
    Node *new_node = new Node();
    new_node->number = number;
    if (ptrHead == NULL)
    {
        new_node->next = new_node;
        new_node->back = new_node;
        ptrHead = new_node;
    }
    else
    {
        Node *last_node = ptrHead->back;

        new_node->next = ptrHead;

        new_node->back = last_node;

        ptrHead->back = new_node;

        last_node->next = new_node;
        ptrHead = new_node;
    }
}

template <typename T>
void CircularList<T>::insert_Last(T number)
{
    Node *new_node = new Node();
    new_node->number = number;
    if (ptrHead == NULL)
    {
        new_node->next = new_node;

        new_node->back = new_node;
        ptrHead = new_node;
    }
    else
    {
        Node *last_node = ptrHead->back;

        new_node->next = ptrHead;

        new_node->back = last_node;

        ptrHead->back = new_node;

        last_node->next = new_node;
    }
}

template <typename T>
bool CircularList<T>::empty()
{
    if (ptrHead == NULL)
        return true;
    else
        return false;
}

template <typename T>
void CircularList<T>::print()
{
    if (!empty())
    {
        Node *temp = ptrHead;
        do
        {
            cout << temp->number<< "- ";

            temp = temp->next;
        } while (temp != ptrHead);
        cout << "\n ";
    }
}

template <typename T>
int CircularList<T>::travel()
{
    int count = 0;
    if (!empty())
    {
        Node *temp = ptrHead;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != ptrHead);
    }
    return count;
}

template <typename T>
void CircularList<T>::remove(int position)
{
    if (position <= travel())
    {
        if (position == 1)
        {
            if (travel() == 1)
            {
                delete ptrHead;
                ptrHead = NULL;
            }
            else
            {
                Node *temp_ptrHead = ptrHead;
                Node *last_node = ptrHead->back;

                ptrHead = ptrHead->next;

                last_node->next = ptrHead;

                ptrHead->back = last_node;

                delete temp_ptrHead;
            }
        }
        else
        {
            Node *temp = ptrHead;
            for (int f = 1; f <= position - 1; f++)
                temp = temp->next;


            Node *temp_ptrHead = temp;
            Node *back = temp->back;

            temp = temp->next;

            back->next = temp;

            temp->back = back;

            delete temp_ptrHead;
        }
    }
}

int main(int argc, char **argv)
{
    CircularList<int> *obj = new CircularList<int>();
    obj->insert_First(1);
    obj->insert_First(2);
    obj->insert_First(3);

    cout << "Nodos Insertados\n ";

    obj->print();
    obj->insert_Last(4);

    obj->insert_Last(5);
    obj->insert_Last(6);
    cout << "Nodos Insertados\n ";

    obj->print();

    cout << "Recorrido:" << obj->travel()<< "\n ";
    cout<< "Remover la primer position:\n ";

    obj->remove(1);
    obj->print();
    delete obj;
    return 0;
}
