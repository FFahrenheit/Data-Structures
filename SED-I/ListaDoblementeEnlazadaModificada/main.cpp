#include <iostream>
#include "ListaDoblementeEnlazada.h"
#include <algorithm>

using namespace std;

bool isInteger(string);
int toInteger(string);
int requestInt(string);
string requestIntAsString(string);

int main (int argc,char *argv[])
{
    List<int> list;
    int n;
    int opc;
    do{
        cout<<"1-.Agregar numero \n";         //Listo
        cout<<"2-.Eliminar numero.\n";          //Listo por ID
        cout<<"3-.Imprimir.\n";        //Listo
        cout<<"4-.Imprimir descendente\n";       //Listo
        cout<<"5-.Esta vacia?\n";                  //Listo
        cout<<"6-.Eliminar primero\n";         //Listo
        cout<<"7-.Eliminar ultimo\n";   //Listo
        cout<<"8-.Eliminar maximo\n";            //Listo
        cout<<"9-.Obtener valor maximo\n";                 //Listo
        cout<<"10-.Eliminar Todo\n";            //TAREA
        cout<<"0-.Salir..\n";                   //Listo

        opc = requestInt("Ingrese una opcion: ");
        system("cls");
         switch (opc){
             case 1:{
             	system ("cls");
             	n = requestInt("Ingrese el nuevo numero: ");
             	list.Add(n);
                list.print();
                break;
             }

             case 2:{
                n = requestInt("Ingrese el numero a eliminar: ");
                list.remove(n);
                list.print();
                break;
             }
             case 3:{
                list.print();
                break;
             }
             case 4:{
                list.printInverse();
                break;
             }
             case 5:{
                if(list.empty())
                {
                    cout << "La lista esta vacia"<<endl;
                }
                else
                {
                    cout << "La lista NO esta vacia" << endl;
                }
                break;
             }
             case 6:{
                cout << "Eliminando el primer elemento ... " << endl;
                list.deleteFirst();
                list.print();
                break;
             }
             case 7:{
                cout << "Eliminando ultimo elemento ... " << endl;
                list.deleteLast();
                list.print();
                break;
             }
             case 8:{
                cout << "Eliminando el elemento mas grande ... " << endl;
                list.deleteMax();
                list.print();
                break;
             }
             case 9:{
                int max = list.getMax();
                if(max != NULL)
                {
                    cout << "El valor maximo es " << max ;
                }
                else
                {
                    cout << "Imposible obtener el valor maximo en una lisa vacia";
                }
                break;
             }
             case 0:
                 cout << "Gracias por usar esta lista" << endl;
             case 10:{
                    list.deleteAll();
                    cout << "Lista eliminada de la memoria" << endl;
                    break;
              }

        }
        cout<<endl;
        system("pause");
        system("cls");
    }while(opc!=0);
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

int requestInt(string const message)
{
    return toInteger(requestIntAsString(message));
}
