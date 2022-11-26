#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>

using namespace std;

/***
    Ismael Ivan Lopez Murillo
    Compilar con >= C++11
***/

void gotoxy(int,int);
bool isInteger(string);
int toInteger(string);
int requestInt(string);

class Pila
{
    private:
        struct Nodo
        {
            int dato;
            Nodo * sig;
            Nodo(int _dato) : dato(_dato){};
        }*tope,*aux;
        string getFormato(int);
    public:
        Pila();
        void push();
        void pop();
        void getTope();
        void mostrar();
        bool vacia();
        ~Pila();
};

Pila::~Pila()
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

Pila::Pila()
{
    tope = nullptr;
}

void Pila::push()
{
    int dato = requestInt("Ingrese el dato: ");
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
    cout << "\n\n\t\tDato agregado correctamente" << endl;
}

void Pila::pop()
{
    if(!vacia())
    {
        aux = tope;
        tope = tope->sig;
        delete(aux);
        cout << "\n\n\t\tDato eliminado" << endl;
    }
    else
    {
        cout << "\n\n\t\tLa pila ya esta vacia" << endl;
    }
}

void Pila::getTope()
{
    if(!vacia())
    {
        cout << "\n\n\t\tEl tope es " << tope->dato << endl;
    }
    else
    {
        cout << "\n\n\t\tLa pila esta vacia" << endl;
    }
}

void Pila::mostrar()
{
    if(!vacia())
    {
        printf("\n\n\t\t%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,187);
        for(aux = tope; aux != nullptr; aux=aux->sig)
        {
            printf("\t\t%c",186);
            cout << getFormato(aux->dato);
            printf("%c\n",186);
            printf("\t\t%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,205,205,185);
        }
    }
    else
    {
        cout << "\n\n\t\tLa pila esta vacia" << endl;
    }
}

bool Pila::vacia()
{
    return tope == nullptr;
}

string Pila::getFormato(int valor)
{
    string n = std::to_string(valor);
    string aux1="",aux2="";
    for(int i=0; i<((int)(7-n.length())/2);i++)
    {
        aux1 += " ";
        aux2 += " ";
    }
    string out = aux1 + n + aux2;
    return out.length() == 7 ? out : out+" ";
}

int main()
{
    Pila pila;
    int opc;
    do
    {
        system("cls");
        pila.mostrar();
        cout << "\n\n[1]. Push\n[2]. Pop\n[3]. Mostrar tope\n";
        cout << "[4]. Mostrar pila\n[5]. Salir" << endl;
        opc = requestInt("Ingrese su eleccion: ");
        system("cls");
        switch(opc)
        {
            case 1:
                pila.push();
                break;
            case 2:
                pila.pop();
                break;
            case 3:
                pila.getTope();
                break;
            case 4:
                pila.mostrar();
                break;
            case 5:
                cout << "Gracias por usar esta pila" << endl;
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
        system("pause");
    }while(opc!=5);
    return 0;
}

 bool isInteger(string s)
{
    if(s.empty())
    {
        return false;
    }
    if(s.at(0)=='-')
    {
        return !s.empty() && all_of(s.begin()+1, s.end(), ::isdigit); //Todo sea digito
    }
    else
    {
        return !s.empty() && all_of(s.begin()+1, s.end(), ::isdigit);
    }
}

int toInteger(string const number)
{
    return std::stoi(number);
}

 int requestInt(string const message)
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
    return toInteger(input);
}


