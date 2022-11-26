#ifndef GRUPO_H
#define GRUPO_H

#include <iostream>
#include "Estudiante.h"

using namespace std;

class Grupo
{
public:
    Grupo();

    //Métodos de interfaz
    void setMateria(const string& valor);
    string getMateria() const;
    void setSeccion(const string& valor);
    string getSeccion() const;
    void setNrc(const string& valor);
    string getNrc() const;

    int getEstudiantesCount();

    //Comportamientos
    void menu();
    void agregarEstudiante();
    void consultarEstudiante(const Estudiante& e) const;
    void consultarLista() const;
    void buscarEstudiante() const;
    void modificarEstudiante();

private:
    //static permite acceder a la constante sin necesidad de crear
    //un objeto
    static const int MAX_ESTUDIANTE = 40;
    string materia;
    string seccion;
    string nrc;
    //El arreglo de estudiantes que será administrado
    Estudiante estudiantes[MAX_ESTUDIANTE];
    //El contador de estudiantes
    int contadorEstudiantes;

    enum Opciones
    {
        OPC_SALIR,
        OPC_AGREGAR,
        OPC_CONSULTAR,
        OPC_BUSCAR,
        OPC_MODIFICAR
    };
};


#endif // GRUPO_H
