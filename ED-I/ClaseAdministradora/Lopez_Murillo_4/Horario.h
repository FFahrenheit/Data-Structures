#ifndef HORARIO_H
#define HORARIO_H


#define HORARIO_H
#include "Grupo.h"
#include <iostream>

using namespace std;

class Horario
{
public:
    Horario();

    string getCicloEscolar() const;
    void setCicloEscolar(const string &value);

    void agregarGrupo();
    //Este método deberá solicitar la materia, sección y nerc del grupo que será
    //registrado.

    void editarGrupo();
    //Este método deberá mostrar la materia, sección y nrc de cada grupo y solicitarle
    //al usuario que seleccione uno para ser editado. Una vez seleccionado
    //un grupo se deberá llamar al método menú de ese grupo particular.

    void mostrarGrupos();
    //Este método deberá mostrar la materia, sección, nrc y cantidad de estudiantes de
    //cada grupo.

    void buscarGrupo();
    //Este método deberá buscar por coincidencia de patrones el nombre de una
    //materia dentro de todos los grupos registrados y mostrar aquellos en los que
    //coincida el patrón.

    void menu();
    //Este método despliega el menú principal del programa en el que se puede
    //Agregar grupo
    //Editar grupo
    //Mostrar grupos
    //Buscar grupo
    //Salir

private:
    static const int MAX_GRUPO = 10;
    string cicloEscolar;
    Grupo grupos[MAX_GRUPO];
    int contadorGrupos;

    enum opcHorario
    {
        OPC_SALIR_HORARIO,
        OPC_AGREGAR_GRUPO,
        OPC_EDITAR_GRUPO,
        OPC_MOSTRAR_GRUPOS,
        OPC_BUSCAR_GRUPO
    };
};


#endif // HORARIO_H
