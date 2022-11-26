//
// Created by ivan_ on 25/03/2021.
//

#include "Casa.h"

Casa::Casa(int numero, const string &calle, const string &propietario) : numero(numero), calle(calle),
                                                                         propietario(propietario) {

}

Casa::Casa() {
    this->numero = 0;
    this->calle = "";
    this->propietario = "";
}

int Casa::getNumero() const {
    return numero;
}

void Casa::setNumero(int numero) {
    Casa::numero = numero;
}

const string &Casa::getCalle() const {
    return calle;
}

void Casa::setCalle(const string &calle) {
    Casa::calle = calle;
}

const string &Casa::getPropietario() const {
    return propietario;
}

void Casa::setPropietario(const string &propietario) {
    Casa::propietario = propietario;
}

bool Casa::operator==(const Casa &rhs) const {
    return numero == rhs.numero;
}

bool Casa::operator!=(const Casa &rhs) const {
    return numero != rhs.numero;
}

bool Casa::operator<(const Casa &rhs) const {
    return numero < rhs.numero;
}

bool Casa::operator>(const Casa &rhs) const {
    return rhs < *this;
}

ostream& operator <<(ostream& os, const Casa& casa)
{
    if(&os == &cout){
        os << "Numero: " << casa.getNumero() << endl;
        os << "Calle: " << casa.getCalle() << endl;
        os << "Propietario: " << casa.getPropietario() << endl;
    }else{
        os << casa.getNumero() << '|' << casa.getCalle()
           << '|' << casa.getPropietario() << '*';
    }
    return os;
}

istream& operator >>(istream& is, Casa& casa)
{
    string aux;
    getline(is, aux, '|'); //Separador de campo

    if (!aux.empty())
    {
        casa.setNumero(stoi(aux));  //Convertir a int
        getline(is, aux, '|'); //Separador de campo
        casa.setCalle(aux);
        getline(is, aux,'*'); //Separador de REGISTRO
        casa.setPropietario(aux);
    }
    return is;
}

