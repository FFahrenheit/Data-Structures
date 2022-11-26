#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>

/***
    Tgo. Ismael Ivan Lopez Murillo
    Compilar con >= C++11
***/

using namespace std;

const int LIMITE_COLA = 10;

void gotoxy(int,int);
bool isInteger(string);
int toInteger(string);
int requestInt(string);

class Cola
{
    private:
        int datos[LIMITE_COLA];
        int inicio;
        int fin;
        string getFormato(int);
    public:
        Cola();
        void push();
        void pop();
        bool vacia();
        bool llena();
        void mostrar();
        void getFin();
        void getInicio();
};

Cola::Cola()
{
    inicio = 0;
    fin = -1;
}

void Cola::push()
{
    if(!llena())
    {
        int dato = requestInt("Ingrese un numero: ");
        datos[++fin] = dato;
        cout << "Dato agregado correctamente" << endl;
    }
    else
    {
        cout << "La cola esta llena" << endl;
    }
}

void Cola::pop()
{
    if(!vacia())
    {
        for(int i=0; i<fin; i++)
        {
            datos[i] = datos[i+1];
        }
        datos[fin] = 0;
        --fin;
        cout << "Pop correcto" << endl;
    }
    else
    {
        cout << "La cola ya esta vacia" << endl;
    }
}

bool Cola::vacia()
{
    return fin == -1;
}

bool Cola::llena()
{
    return fin == LIMITE_COLA-1;
}

void Cola::mostrar()
{
    if(!vacia())
    {
        printf("\n\n\t\t%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,187);
        for(int i=fin; i>=0; i--)  //Se imprime de arriba a abajo
        {
            printf("\t\t%c",186);
            cout << getFormato(datos[i]);
            printf("%c\n",186);
            printf("\t\t%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,205,205,185);
        }
    }
    else
    {
        cout << "\n\n\t\tLa cola esta vacia" << endl;
    }
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

void Cola::getFin()
{
    if(!vacia())
    {
        cout << "En el fin esta " << datos[fin] << endl;
    }
    else
    {
        cout << "La cola esta vacia, no hay dato en el fin" << endl;
    }
}

void Cola::getInicio()
{
    if(!vacia())
    {
        cout << "En el inicio esta " << datos[inicio] << endl;
    }
    else
    {
        cout << "La cola esta vacia, no hay dato en el inicio" << endl;
    }
}

int main()
{
    Cola cola;
    int opc;
    do
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
        opc = requestInt("Ingrese su eleccion: ");
        system("cls");
        switch(opc)
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
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
        system("pause");
    }while(opc!=6);
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

