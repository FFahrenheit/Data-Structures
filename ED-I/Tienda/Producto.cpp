//
// Created by ivan_ on 12/11/2020.
//

#include "Producto.h"

Producto::~Producto() {

}

Producto::Producto()
{
    nombre = "";
    precio = 0.0;
    existencia = 0;
}

const string &Producto::getNombre() const {
    return nombre;
}

void Producto::setNombre(const string &nombre) {
    Producto::nombre = nombre;
}

float Producto::getPrecio() const {
    return precio;
}

void Producto::setPrecio(float precio) {
    Producto::precio = precio;
}

int Producto::getExistencia() const {
    return existencia;
}

void Producto::setExistencia(int existencia) {
    Producto::existencia = existencia;
}

ostream& operator <<(ostream& os, const Producto& obj)
{
    os <<obj.getNombre() <<"|" <<obj.getPrecio() <<"|" <<obj.getExistencia() <<'*';

    return os;
}

istream& operator >>(istream& is, Producto& obj)
{
    string aux;
    getline(is, aux, '|');

    if (!aux.empty())
    {
        obj.setNombre(aux);
        getline(is, aux, '|');
        obj.setPrecio(stof(aux)); //StringTOFloat
        getline(is, aux,'*');
        obj.setExistencia(stoi(aux)); //StringTOInteger
    }

    return is;
}

bool Producto::operator==(const Producto &p) const{
    return getNombre() == p.getNombre();
}

bool Producto::operator>(const Producto &p) const{
    return getNombre().compare(p.getNombre()) > 0;
}

bool Producto::operator<(const Producto &p) const{
    return getNombre().compare(p.getNombre()) < 0;
}

bool Producto::operator<=(const Producto &p) const{
    return getNombre().compare(p.getNombre()) <= 0;
}

bool Producto::operator>=(const Producto &p) const{
    return getNombre().compare(p.getNombre()) >= 0;
}

bool Producto::operator!=(const Producto &p) const{
    return getNombre() != p.getNombre();
}
