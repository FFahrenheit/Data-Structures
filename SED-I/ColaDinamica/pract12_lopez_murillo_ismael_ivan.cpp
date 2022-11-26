#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>

using namespace std;

/***
    Tgo. Ismael Ivan Lopez Murillo
    Compilar con >= C++11
***/

void gotoxy(int,int);
bool isInteger(string);
int toInteger(string);
int requestInt(string);

class Cola
{
    private:
        struct Nodo
        {
            int dato;
            Nodo * sig;
            Nodo(int _dato) : dato(_dato){};
        }*frente,*aux, *fin;
        string getFormato(int);
    public:
        Cola();
        void push();
        void pop();
        void getInicio();
        void getFin();
        void mostrar();
        bool vacia();
        ~Cola();
};

Cola::~Cola()
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

Cola::Cola()
{
    fin = nullptr;
    frente = nullptr;
}

void Cola::push()
{
    int dato = requestInt("Ingrese el dato: ");
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
    cout << "\n\n\t\tDato agregado correctamente" << endl;
}

void Cola::pop()
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
        cout << "\n\n\t\tDato eliminado" << endl;
    }
    else
    {
        cout << "\n\n\t\tLa cola ya esta vacia" << endl;
    }
}

void Cola::getFin()
{
    if(!vacia())
    {
        cout << "\n\n\t\tEl valor en el fin es " << fin->dato << endl;
    }
    else
    {
        cout << "\n\n\t\tLa cola esta vacia" << endl;
    }
}

void Cola::getInicio()
{
    if(!vacia())
    {
        cout << "\n\n\t\tEl valor en el inicio es " << frente->dato << endl;
    }
    else
    {
        cout << "\n\n\t\tLa cola esta vacia" << endl;
    }
}

void Cola::mostrar()
{
    if(!vacia())
    {
        printf("\n\n\t\t%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,187);
        for(aux = fin; aux != nullptr; aux=aux->sig)
        {
            printf("\t\t%c",186);
            cout << getFormato(aux->dato);
            printf("%c\n",186);
            printf("\t\t%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,205,205,185);
        }
    }
    else
    {
        cout << "\n\n\t\tLa cola esta vacia" << endl;
    }
}

bool Cola::vacia()
{
    return frente == nullptr;
}

string Cola::getFormato(int valor)
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

int menu(Cola&);

int menu(Cola &cola)
{
    system("cls");
    cola.mostrar();
    cout << "\n\n\t\tMenu para cola" << endl;
    cout << "[1]. Encolar (Push)" << endl;
    cout << "[2]. Mostrar inicio" << endl;
    cout << "[3]. Mostrar fin" << endl;
    cout << "[4]. Desencolar (pop)" << endl;
    cout << "[5]. Mostrar cola" << endl;
    cout << "[6]. Salir" << endl;
    int opc = requestInt("Ingrese su eleccion: ");
    system("cls");
    return opc;
}

int main()
{
    Cola cola;
    do
    {
        switch(menu(cola))
        {
            case 1:
                cola.push();
                break;
            case 2:
                cola.getInicio();
                break;
            case 3:
                cola.getFin();
                break;
            case 4:
                cola.pop();
                break;
            case 5:
                cola.mostrar();
                break;
            case 6:
                cout << "Gracias por usar esta estructura de cola" << endl;
                return 0;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
        system("pause");
    }while(true);
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


