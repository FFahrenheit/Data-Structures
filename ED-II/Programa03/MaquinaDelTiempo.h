//
// Created by ivan_ on 14/04/2021.
//

#ifndef PROGRAMA03_MAQUINADELTIEMPO_H
#define PROGRAMA03_MAQUINADELTIEMPO_H

#include <iostream>
#include "Grafo.h"
#include "Evento.h"

using namespace std;

class MaquinaDelTiempo {
private:
    Grafo<Evento> eventos;
    string FILENAME;
public:
    MaquinaDelTiempo(){
       eventos = Grafo<Evento>();
       FILENAME = "file01.txt";
    }
    void menu();

    void nuevoEvento();

    void nuevoEnlace();

    void detallesEvento();

    void borrarEvento();

    void borrarSalto();

    void guardar();

    void cargar();
};

void MaquinaDelTiempo::menu() {
    char opc;
    cout << "Desea importar la lista de eventos desde el archivo? Y / N: ";
    cin >> opc;
    if(opc=='Y' || opc == 'y'){
        cargar();
        system("pause");
    }
    do{
        system("cls");
        cout << "\n\t\tMenu para Maquina del tiempo\n\n";
        cout << "1)Agregar evento (vertice)\n";
        cout << "2)Agregar salto temporal (arista)\n";
        cout << "3)Detalles sobre evento\n";
        cout << "4)Mostrar mapa temporal (todo el grafo)\n";
        cout << "5)Borrar evento de la existencia\n";
        cout << "6)Borrar salto temporal\n";
        cout << "7)Guardar a archivo\n";
        cout << "8)Cargar desde archivo\n";
        cout << "9)Salir (sin repercusiones)\n";
        cout << "0)Salir (sin repercusiones)\n";
        cout << "Su eleccion: ";

        cin >> opc;

        switch(opc){
            case '1':
                nuevoEvento();
                break;
            case '2':
                nuevoEnlace();
                break;
            case '3':
                detallesEvento();
                break;
            case '4':
                eventos.mostrar();
                break;
            case '5':
                borrarEvento();
                break;
            case '6':
                borrarSalto();
                break;
            case '7':
                guardar();
                break;
            case '8':
                cargar();
                break;
            case '9':
            case '0':
                cout << "Gracias por crear un multiverso mas\n";
                break;
            default:
                cout << "Ingrese una opcion valida\n";
                break;
        }
        system("pause");

    }while(opc!='0' && opc!='9');
}

void MaquinaDelTiempo::nuevoEvento() {
    Evento evento = Evento();
    evento.setEvento(); //get evento
    if(eventos.agregar_vertice(evento)){
        cout << "Evento agregado\n";
    }else{
        cout << "No puede agregar eventos repetidos, generaria mas paradojas\n";
    }
}

void MaquinaDelTiempo::nuevoEnlace() {
    int origen, destino, costo;
    cout << "Elija el evento de origen (escriba id)\n";
    this->eventos.listar();
    cin >> origen;

    cout << "Elija el evento de destino (escriba id)\n";
    this->eventos.listar();
    cin >> destino;

    cout << "Ingrese el costo del viaje (en unidades Fourier): ";
    cin >> costo;

    if(eventos.agregar_arista(Evento(origen),Evento(destino),costo)){
        cout << "Salto temporal agregado\n";
    }else{
        cout << "No se pudo agregar el salto. Verifique que no exista un salto y que existan los eventos \n";
    }
}

void MaquinaDelTiempo::detallesEvento() {
    int id;
    cout << "Ingrese el Id del evento (CONFIDENCIAL): ";
    cin >> id;

    int pos = eventos.get_vertices().find(Evento(id));

    if(pos == -1){
        cout << "No existe el evento (aun)" << endl;
    }else{
        eventos.get_vertices().get(pos).mostrar();
    }
}

void MaquinaDelTiempo::borrarEvento() {
    int id;
    cout << "Ingrese el Id del evento a eliminar: \n";
    eventos.listar();
    cin >> id;

    if(eventos.eliminar_vertice(Evento(id))){
        cout << "Evento eliminado\n";
    }else{
        cout << "Error: El evento ya no existio (o existira?)\n";
    }
}

void MaquinaDelTiempo::borrarSalto() {
    int origen, destino;
    cout << "Elija el evento de origen (escriba id)\n";
    this->eventos.listar();
    cin >> origen;


    cout << "Elija el evento de destino (escriba id)\n";
    this->eventos.listar();
    cin >> destino;

    if(eventos.eliminar_arista(Evento(origen),Evento(destino))){
        cout << "Salto temporal eliminado\n";
    }else{
        cout << "Otro viajero se adelanto y borro este salto del tiempo \n";
    }
}

void MaquinaDelTiempo::guardar() {
    if(eventos.guardar(FILENAME)){
        cout << "Multiverso guardado\n";
    }else{
        cout << "ERROR. No se pudo guardar el multiverso, probablemente ya no existe\n";
    }
}

void MaquinaDelTiempo::cargar() {
    if(eventos.cargar(FILENAME)){
        cout << "Multiverso guardado\n";
    }else{
        cout << "ERROR. No se pudo guardar el multiverso, probablemente ya no existe\n";
    }
}


#endif //PROGRAMA03_MAQUINADELTIEMPO_H
