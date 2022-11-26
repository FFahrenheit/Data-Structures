#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
using namespace std;

class Estudiante
{
public:
    Estudiante();

    void setCarrera(const string& valor);
    string getCarrera() const;

    void setCodigo(const string& valor);
    string getCodigo() const;

    void setNombre(const string& valor);
    string getNombre() const;

private:
    string carrera;
    string codigo;
    string nombre;
};
#endif // ESTUDIANTE_H
