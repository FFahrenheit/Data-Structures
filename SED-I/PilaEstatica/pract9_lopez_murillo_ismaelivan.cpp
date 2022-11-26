#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>

/***
    Ismael Ivan Lopez Murillo
    Compilar con >= C++11
***/

using namespace std;

const int LIMITE_PILA = 10;

void gotoxy(int,int);
bool isInteger(string);
int toInteger(string);
int requestInt(string);

class Pila
{
    private:
        int datos[LIMITE_PILA];
        int tope;
        string getFormato(int);
    public:
        Pila();
        void push();
        void pop();
        bool vacia();
        bool llena();
        void mostrar();
        void getTope();
};

Pila::Pila()
{
    tope = -1;
}

void Pila::push()
{
    if(!llena())
    {
        int dato = requestInt("Ingrese un numero: ");
        datos[++tope] = dato;
        cout << "Dato agregado correctamente" << endl;
    }
    else
    {
        cout << "La pila esta llena" << endl;
    }
}

void Pila::pop()
{
    if(!vacia())
    {
        datos[tope--] = 0;
        cout << "Pop correcto" << endl;
    }
    else
    {
        cout << "La pila ya esta vacia" << endl;
    }
}

bool Pila::vacia()
{
    return tope == -1;
}

bool Pila::llena()
{
    return tope == LIMITE_PILA-1;
}

void Pila::mostrar()
{
    if(!vacia())
    {
        printf("\n\n\t\t%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,187);
        for(int i=tope; i>=0; i--)  //Se imprime de arriba a abajo
        {
            printf("\t\t%c",186);
            cout << getFormato(datos[i]);
            printf("%c\n",186);
            printf("\t\t%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,205,205,185);
        }
    }
    else
    {
        cout << "\n\n\t\tLa pila esta vacia" << endl;
    }
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

void Pila::getTope()
{
    if(!vacia())
    {
        cout << "El tope es " << datos[tope] << endl;
    }
    else
    {
        cout << "La pila esta vacia, no hay tope" << endl;
    }
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

 void gotoxy(int x,int y)
 {
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
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

