#include "Dato.h"

Dato::Dato(){
    id = 0;
    nombre = "";
    direccion = "";
    mail = "";
}

Dato::~Dato(){
}

Dato::Dato(int i,const string& n,const string& d,const string&m){
    id = i;
    nombre = n;
    direccion = d;
    mail = m;
}

int Dato::getId() const{
    return id;
}

const string& Dato::getNombre() const{
    return nombre;
}

const string& Dato::getDireccion() const{
    return direccion;
}

const string& Dato::getMail() const{
    return mail;
}

void Dato::setId(int i){
    id = i;
}

void Dato::setNombre(const string& n){
    nombre = n;
}

void Dato::setDireccion(const string& d){
    direccion = d;
}

void Dato::setMail(const string& m){
    mail = m;
}

ostream& operator <<(ostream& os, const Dato& dato)
{
    os << dato.getId();
    return os;
}
bool Dato::operator==(const Dato &d) const{
    return getId() == d.getId();
}

bool Dato::operator>(const Dato &d) const{
    return getId() > d.getId();
}

bool Dato::operator<(const Dato &d) const{
    return getId() < d.getId();
}

void Dato::imprimir() const
{
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre<< endl;
    cout << "Direccion: " << direccion<< endl;
    cout << "Mail: " << mail<< endl;
}
