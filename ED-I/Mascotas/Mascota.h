//
// Created by ivan_ on 24/09/2020.
//

#ifndef MASCOTAS_MASCOTA_H
#define MASCOTAS_MASCOTA_H

#include <iostream>
#include <string.h>

using namespace std;

class Mascota
{
    private:
        string nombre;
        int edad;
        string tipo;
    public:
        Mascota();
        ~Mascota();
        const string &getNombre() const;
        void setNombre(const string &nombre);
        int getEdad() const;
        void setEdad(int edad);
        const string &getTipo() const;
        void setTipo(const string &tipo);
        void comer(const string &comida);
};


#endif //MASCOTAS_MASCOTA_H
