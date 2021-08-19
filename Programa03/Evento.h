//
// Created by ivan_ on 14/04/2021.
//

#ifndef PROGRAMA03_EVENTO_H
#define PROGRAMA03_EVENTO_H

#include <iostream>
using namespace std;

class Evento {
private:
    int id_suceso;
    string descripcion;
    string fecha;
public:
    Evento(){};
    Evento(int id){
        id_suceso = id;
    }

    int getIdSuceso() const {
        return id_suceso;
    }

    void setIdSuceso(int idSuceso) {
        id_suceso = idSuceso;
    }

    const string &getDescripcion() const {
        return descripcion;
    }

    void setDescripcion(const string &descripcion) {
        Evento::descripcion = descripcion;
    }

    const string &getFecha() const {
        return fecha;
    }

    void setFecha(const string &fecha) {
        Evento::fecha = fecha;
    }

    friend  ostream& operator <<(ostream& os, const Evento& evento)
    {
        if(&os == &cout){
            os << "Id suceso: " << evento.getIdSuceso() << endl;
            os << "Descripcion: " << evento.getDescripcion() << endl;
            os << "Fecha: " << evento.getFecha() << endl;
        }else{
            os << evento.getIdSuceso() << '|' << evento.getDescripcion()
               << '|' << evento.getFecha() << '*';
        }
        return os;
    }

    friend istream& operator >>(istream& is, Evento& evento)
    {
        string aux;
        getline(is, aux, '|'); //Separador de campo

        if (!aux.empty())
        {
            evento.setIdSuceso(stoi(aux));  //Convertir a int
            getline(is, aux, '|'); //Separador de campo
            evento.setDescripcion(aux);
            getline(is, aux,'*'); //Separador de REGISTRO
            evento.setFecha(aux);
        }
        return is;
    }

    bool operator==(const Evento &rhs) const {
        return id_suceso == rhs.id_suceso;
    }

    bool operator!=(const Evento &rhs) const {
        return !(rhs == *this);
    }

    void setEvento(){
        cout << "Ingrese el id del evento: ";
        cin >> id_suceso;
        cin.ignore();

        cout << "Ingrese la descripcion del evento: ";
        getline(cin,descripcion);

        cout << "Ingrese la fecha del evento: ";
        getline(cin,fecha);
    }
};

#endif //PROGRAMA03_EVENTO_H
