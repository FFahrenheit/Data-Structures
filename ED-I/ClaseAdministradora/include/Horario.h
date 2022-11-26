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
    //Este m�todo deber� solicitar la materia, secci�n y nerc del grupo que ser�
    //registrado.

    void editarGrupo();
    //Este m�todo deber� mostrar la materia, secci�n y nrc de cada grupo y solicitarle
    //al usuario que seleccione uno para ser editado. Una vez seleccionado
    //un grupo se deber� llamar al m�todo men� de ese grupo particular.

    void mostrarGrupos();
    //Este m�todo deber� mostrar la materia, secci�n, nrc y cantidad de estudiantes de
    //cada grupo.

    void buscarGrupo();
    //Este m�todo deber� buscar por coincidencia de patrones el nombre de una
    //materia dentro de todos los grupos registrados y mostrar aquellos en los que
    //coincida el patr�n.

    void menu();
    //Este m�todo despliega el men� principal del programa en el que se puede
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
