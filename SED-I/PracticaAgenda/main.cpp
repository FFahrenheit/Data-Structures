#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

struct agenda
{
    int cve;
    string nombre;
    string direccion;
    char email[30];
    char telefono[10];
}a[10];

int index = 0;
int counter = 1;

void menu();
void registrar();
int buscar(int);
void mostrar();
void editar(int);
void remover();
void listar();
void mostrar(int);

int main()
{
    int opc;
    do
    {
        system("cls");
        menu();
        cout << endl << "¿Continuar?\n 1: Si\n2: No"<<endl;
        cin >> opc;
    }while(opc!=2);
    system("pause");
    system("cls");
    return 0;
}

void menu()
{
    int opc = 0, cve, busqueda;
    cout << "Agenda" << endl;
    cout << "1) Registrar" << endl;
    cout << "2) Buscar por clave" << endl;
    cout << "3) Editar" << endl;
    cout << "4) Remover" << endl;
    cout << "5) Mostrar" << endl;
    cout << "6) Salir" << endl;
    cout << "Seleccione una opcion: " << endl;
    cin >> opc;
    system("cls");
    switch(opc)
    {
        case 1:
            if(index>=9)
            {
                cout << "No hay mas espacio" << endl;
            }
            else
            {
                registrar();
            }
            break;
        case 2:
            cout << "Ingrese la clave del contacto: " <<endl;
            cin >> cve;
            busqueda = buscar(cve);
            if(busqueda!=-1)
            {
                mostrar(busqueda);
            }
            else
            {
                cout << "No se encontro el contacto en la agenda"<<endl;
            }
            break;
        case 3:
            cout << "Ingrese la clave del contacto a editar: " <<endl;
            cin >> cve;
            busqueda = buscar(cve);
            if(busqueda!=-1)
            {
                editar(busqueda);
            }
            else
            {
                cout << "No se encontro el contacto en la agenda"<<endl;
            }
            break;
        case 4:
            remover();
            break;
        case 5:
            listar();
            break;
        case 6:
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;
            system("pause");
            break;
    }
}

void registrar()
{
    cin.ignore();
    a[index].cve = counter;
    cout << "Ingrese nombre: "<<endl;
    getline(cin,a[index].nombre);
    cout << "Ingrese direccion: "<<endl;
    getline(cin,a[index].direccion);
    cout << "Ingrese email: "<<endl;
    cin >> a[index].email;
    cout << "Ingrese telefono: "<<endl;
    cin >> a[index].telefono;
    counter++;
    index++;
}

int buscar(int cve)
{
    int i=0;
    while(i<=index)
    {
        if(a[i].cve == cve)
        {
            return i;
        }
        else
        {
            i++;
        }
    }
    return -1;
}

void mostrar(int pos)
{
    cout << "Clave: " << a[pos].cve << endl;
    cout << "Nombre: " << a[pos].direccion << endl;
    cout << "Direccion: " << a[pos].nombre << endl;
    cout << "Email: " << a[pos].email << endl;
    cout << "Telefono: " << a[pos].telefono << endl;
}

void editar(int pos)
{
    int selec;
    cout << "Elija el comapo a editar" <<endl;
    cout << "1) Nombre ("<< a[pos].nombre << ")"<<endl;
    cout << "2) Direccion ("<< a[pos].direccion << ")"<<endl;
    cout << "3) Email ("<< a[pos].email << ")"<<endl;
    cout << "4) Telefono ("<< a[pos].telefono << ")"<<endl;
    cout << "5) Acabar" << endl;
    cin >> selec;
    cin.ignore();
    switch(selec)
    {
        case 1:
            cout << "Ingrese nuevo nombre"<<endl;
            getline(cin, a[pos].nombre);
            break;
        case 2:
            cout << "Ingrese nueva direccion"<<endl;
            getline(cin, a[pos].direccion);
            break;
        case 3:
            cout << "Ingrese nuevo email"<<endl;
            cin >> a[pos].email;
            break;
        case 4:
            cout << "Ingrese nuevo telefono"<<endl;
            cin >> a[pos].telefono;
            break;
        default:
            break;
    }
}

void remover()
{
    int cve;
    cout << "Ingrese la clave del contacto: " <<endl;
    cin >> cve;
    int busqueda = buscar(cve);
    if(busqueda!=-1)
    {
        for(int i = busqueda; i<index-1; i++)
        {
            a[i] = a[i+1];
        }
        index--;
        cout << "Entrada removida"<<endl;
    }
    else
    {
        cout << "No se encontro el contacto en la agenda"<<endl;
    }
}

void listar()
{
    for(int i=0; i<index;i++)
    {
        mostrar(i);
        cout << "---------------"<<endl;
    }
}
