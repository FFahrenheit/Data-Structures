#include "Estudiante.h"

Estudiante::Estudiante()
{
    nombre = "-";
    carrera = "-";
    codigo = "-";
}

void Estudiante::setNombre(const string &valor)
{
    nombre = valor;
}

string Estudiante::getNombre() const
{
    return nombre;
}

void Estudiante::setCarrera(const string &valor)
{
    carrera = valor;
}

string Estudiante::getCarrera() const
{
    return carrera;
}

void Estudiante::setCodigo(const string &valor)
{
    codigo = valor;
}

string Estudiante::getCodigo() const
{
    return codigo;
}
