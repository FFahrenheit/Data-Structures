#ifndef PASAJERO_H
#define PASAJERO_H

#include <iostream>
using namespace std;

class Pasajero
{
    private:
        string nombre;
        string destino;
        string fecha;
        int boleto;
        int id;
        void gotoxy(int,int);
    public:
        void tomarTaxi(int);
        void bajarAvion(int);
        void imprimirInfo();
        void checarEquipaje(int,int);
        void setNombre(string);
        void setDestino(string);
        void setFecha(string);
        void setBoleto(int);
        void setId(int);
        string getNombre();
        string getDestino();
        string getFecha();
        int getBoleto();
        int getId();
        Pasajero(int);
        Pasajero();
        virtual ~Pasajero();
};

#endif // PASAJERO_H
