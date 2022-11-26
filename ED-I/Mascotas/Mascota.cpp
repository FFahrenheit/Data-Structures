//
// Created by ivan_ on 24/09/2020.
//

#include "Mascota.h"

Mascota::Mascota()
{
    this->nombre = "";
    this->edad = 0;
    this->tipo = "";
}

Mascota::~Mascota()
{
    string primavera = getEdad() == 1 ?  " primavera" : " primaveras";
    string tipo = getTipo().back() == 'a' ? "las " : "los ";
    cout << getNombre() << " ha ido al paraiso de la memoria estatica de " << tipo << getTipo() << "s";
    cout << " tras " << getEdad() << primavera << endl;
}

const string &Mascota::getNombre() const {
    return nombre;
}

void Mascota::setNombre(const string &nombre) {
    Mascota::nombre = nombre;
}

int Mascota::getEdad() const {
    return edad;
}

void Mascota::setEdad(int edad) {
    Mascota::edad = edad;
}

const string &Mascota::getTipo() const {
    return tipo;
}

void Mascota::setTipo(const string &tipo) {
    Mascota::tipo = tipo;
}

void Mascota::comer(const string &comida)
{
    string esp = (getNombre().back() == 'a') ? "La " : "El ";
    string cont = (getEdad() == 1) ? " primavera" : " primaveras"; //Ambos sabemos porqué así
    cout << esp << getTipo() << " " << getNombre() << " de " << getEdad();
    cout << cont << " come " << comida << endl;
}