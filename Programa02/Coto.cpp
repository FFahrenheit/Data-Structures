//
// Created by ivan_ on 25/03/2021.
//

#include "Coto.h"

Coto::Coto() {
    this->casas = Arbol<Casa>();
}

void Coto::menu() {
    char opc;
    int casa;
    Casa temporal, * ptrCasa;
    cout << "Desea importar la lista de casas desde el archivo? Y / N: ";
    cin >> opc;
    if(opc=='Y' || opc == 'y'){
        this->casas.load(FILENAME);
        system("pause");
    }
    do{
        system("cls");
        cout << "\n\t\tMenu Coto Manzana II\n\n";
        cout << "1) Agregar casa" << endl;
        cout << "2) Buscar informacion de casa" << endl;
        cout << "3) Eliminar casa del registro" << endl;
        cout << "4) Recorrido preorden" << endl;
        cout << "5) Recorrido inorden" << endl;
        cout << "6) Recorrido postorden" << endl;
        cout << "7) Mostrar grafico (Windows, solo numero)" << endl;
        cout << "8) Guardar en un archivo" << endl;
        cout << "9) Cargar desde archivo" << endl;
        cout << "0) Salir " << endl;
        cout << "Su eleccion: ";

        cin >> opc;

        switch(opc){
            case '1':
                nuevaCasa();
                break;
            case '2':
                cout << "Ingrese el numero de casa: ";
                cin >> casa;
                temporal.setNumero(casa);
                ptrCasa = &casas.buscar(temporal);
                if(ptrCasa != nullptr){
                    cout << *ptrCasa;
                }else{
                    cout << "No encontrado";
                }
                break;
            case '3':
                cout << "Ingrese el numero de casa: ";
                cin >> casa;
                temporal.setNumero(casa);
                casas.eliminar(temporal);
                break;
            case '4':
                casas.imprimirPre();
                break;
            case '5':
                casas.imprimirIn();
                break;
            case '6':
                casas.imprimirPost();
                break;
            case '7':
                casas.imprimir();
                break;
            case '8':
                casas.save(FILENAME);
                break;
            case '9':
                casas.load(FILENAME);
                break;
            case '0':
                cout << "Adios" << endl;
                this->casas.borrar();
                break;
            default:
                cout << "Ingrese una opcion valida";
                break;
        }
        cout << endl;
        system("pause");
    }while(opc!='0');
}

void Coto::nuevaCasa() {
    Casa casa = Casa();
    int numero;
    string calle, propietario;

    cout << "Ingrese el numero de la casa: ";
    cin >> numero;
    casa.setNumero(numero);
    cin.ignore();

    cout << "Ingrese la calle: ";
    getline(cin,calle);
    casa.setCalle(calle);

    cout << "Ingrese el propietario: ";
    getline(cin,propietario);
    casa.setPropietario(propietario);

    this->casas.agregar(casa);
}

