/***
 * Ismael Ivan Lopez Murillo
***/

#include <iostream>
#include <algorithm>
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
    T search(int);
    void modify(int, T);
};

template <typename T>
void CircularList<T>::modify(int position, T valor)
{
    if(position <= travel() && position > 0)
    {
        int count = 1;
        Node * temp = ptrHead;
        while(count!=position && temp)
        {
            temp = temp->next;
        }
        if(count == position)
        {
            temp->number = valor;
        }
    }
}

template <typename T>
T CircularList<T>::search(int position)
{
    if(position > travel() || position <= 0)
    {
        return NULL;
    }
    int count = 1;
    Node * temp = ptrHead;
    while(count!=position && temp)
    {
        temp = temp->next;
    }
    return temp->number;
}

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

int toInteger(string const);
int requestInt(string const);
bool isInteger(string);
string requestIntAsString(string const);


int main(int argc, char **argv)
{
    CircularList<int> *list = new CircularList<int>();
    int opc;
    int valor;
    do
    {
        system("cls");
        cout << "\t\tMenu" << endl << endl;
        cout << "1) Insertar al Principio" << endl;
        cout << "2) Insertar al Final" << endl;
        cout << "3) Buscar por Posicion" << endl;
        cout << "4) Modificar" << endl;
        cout << "5) Remover" << endl;
        cout << "6) Listar / imprimir" << endl;
        cout << "7) Salir" << endl;
        opc = requestInt("Ingrese su opcion: ");
        switch(opc)
        {
            case 1:
                valor = requestInt("Ingrese el dato a agregar al inicio: ");
                list->insert_First(valor);
                cout << "Dato agregado" << endl;
                break;
            case 2:
                valor = requestInt("Ingrese el dato a agregar al final: ");
                list->insert_Last(valor);
                cout << "Dato agregado" << endl;
                break;
            case 3:
                {
                    valor = requestInt("Ingrese la posicion a buscar: ");
                    int encontrado = list->search(valor);
                    if(encontrado != NULL)
                    {
                        cout << "Se encontro: " << encontrado << endl;
                    }
                    else
                    {
                        cout << "No se encontro el valor en la posicion dada" << endl;
                    }
                    break;
                }
            case 4:
                {
                    valor = requestInt("Ingrese la posicion a modificar: ");
                    int nuevoValor = requestInt("Ingrese el nuevo valor: ");
                    if(list->search(valor))
                    {
                        list->modify(valor,nuevoValor);
                        cout << "Dato modificado" << endl;
                    }
                    else
                    {
                        cout << "No se puede modificar el dato" << endl;
                    }
                    break;
                }
            case 5:
                valor = requestInt("Ingrese la posicion a eliminar: ");
                list->remove(valor);
                break;
            case 6:
                list->print();
                break;
            case 7:
                cout << "Gracias por usar este programa" << endl;
                return 0;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
        system("pause");
    }while(opc!=7);
}

int toInteger(string const number)
{
    return std::stoi(number);
}

int requestInt(string const message)
{
    return toInteger(requestIntAsString(message));
}

string requestIntAsString(string const message)
{
    string input;
    do
    {
        cout << message;
        getline(cin,input);
        if(!isInteger(input))
        {
            cout << "Ingrese una entrada valida" << endl;
        }
    }while(!isInteger(input));
    return input;
}


bool isInteger(string s)
{
    if(s.empty())
    {
        return false;
    }
    if(s.at(0)=='-' || s.at(0) == '+')
    {
        return !s.empty() && all_of(s.begin()+1, s.end(), ::isdigit); //Todo sea digito
    }
    else
    {
        return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
    }
}

