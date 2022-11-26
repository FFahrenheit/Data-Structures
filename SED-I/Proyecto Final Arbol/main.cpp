#include <iostream>
#include <algorithm>
#include "Arbol.h"
#include "Dato.h"

using namespace std;

int toInteger(string const);
int requestInt(string const);
bool isInteger(string);
string requestIntAsString(string const);

Arbol<Dato> arbol = Arbol<Dato>();

void agregarNodo()
{
    string nombre, direccion, mail;

    int id = requestInt("Inserte el ID del contacto: ");

    cout << "Ingrese el nombre del contacto: ";
    getline(cin, nombre);
    cout << "Ingrese la direccion del contacto: ";
    getline(cin, direccion);
    do
    {
        cout << "Ingrese un correo valido con dominio @mail.com: ";
        getline(cin,mail);
    }while(mail.find("@mail.com",1) == string::npos);

    arbol.agregar(Dato(id,nombre,direccion,mail));
}

void modificarNodo()
{
    int id = requestInt("Ingrese el ID del contacto a modificar: ");
    Dato busqueda = Dato();
    busqueda.setId(id);
    Dato * d = &arbol.buscar(busqueda);
    if(d != nullptr)
    {
        string nombre,direccion,mail;
        cout << "DATOS DEL NODO";
        d->imprimir();
        cout << "----------------------------------------------------\n";
        cout << "Ingrese el nuevo nombre: ";
        getline(cin, nombre);
        d->setNombre(nombre);
        cout << "Ingrese la nueva direccion: ";
        getline(cin,direccion);
        d->setDireccion(direccion);
        do
        {
            cout << "Ingrese un correo valido con dominio @mail.com: ";
            getline(cin,mail);

        }while(mail.find("@mail.com",1) == string::npos);
        d->setMail(mail);
    }
    else
    {
        cout << "No se ha encontrado el contacto en el arbol" << endl;
    }
}

void buscarNodo()
{
    int id = requestInt("Ingrese el ID del contacto a buscar: ");
    Dato busqueda = Dato();
    busqueda.setId(id);
    Dato * d = &arbol.buscar(busqueda);
    if(d != nullptr)
    {
        cout << "DATOS DEL NODO" << endl;
        d->imprimir();
    }
    else
    {
        cout << "No se ha encontrado el contacto en el arbol" << endl;
    }
}

void eliminarNodo()
{
    int nodo = requestInt("Ingrese el ID del contacto a eliminar: ");
    Dato d = Dato();
    d.setId(nodo);
    arbol.eliminar(d);
}

int main()
{
    int opc;
    do
    {
        system("cls");

        cout << "\t\tMenu" << endl;
        cout << "1) Agregar nodo" << endl;
        cout << "2) Recorrido preorden" << endl;
        cout << "3) Recorrido inorden" << endl;
        cout << "4) Recorrido postorden" << endl;
        cout << "5) Buscar por ID" << endl;
        cout << "6) Modificar nodo" << endl;
        cout << "7) Eliminar nodo" << endl;
        cout << "8) Mostrar arbol" << endl;
        cout << "0) Salir" << endl;

        opc = requestInt("Ingrese su eleccion: ");

        system("cls");

        switch(opc)
        {
            case 1:
                agregarNodo();
                break;
            case 2:
                arbol.imprimir();
                cout << "\n\n\n\n\t\tRecorrido preorden\n";
                arbol.imprimirPre();
                cout << "\n\n";
                break;
            case 3:
                arbol.imprimir();
                cout << "\n\n\n\n\t\tRecorrido inorden\n";
                arbol.imprimirIn();
                cout << "\n\n";
                break;
            case 4:
                arbol.imprimir();
                cout << "\n\n\n\n\t\tRecorrido postorden\n";
                arbol.imprimirPost();
                cout << "\n\n";
                break;
            case 5:
                buscarNodo();
                break;
            case 6:
                modificarNodo();
                break;
            case 7:
                eliminarNodo();
                break;
            case 8:
                arbol.imprimir();
                cout << "\n\n\n\n";
                break;
            case 0:
                cout << "Gracias por usar este programa" << endl;
                return 0;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
        system("pause");

    }while(opc!=0);

    return 0;
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
