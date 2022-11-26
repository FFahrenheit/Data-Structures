#include "Horario.h"

Horario::Horario()
{
    contadorGrupos = 0;
}

string Horario::getCicloEscolar() const
{
    return cicloEscolar;
}

void Horario::setCicloEscolar(const string &value)
{
    cicloEscolar = value;
}

void Horario::agregarGrupo()
{
    //Este método deberá solicitar la materia, sección y nrc del grupo que será
    //registrado.
    string materia;
    string seccion;
    string nrc;

    cout <<"                        Agregar Grupo" <<endl <<endl
        <<"Materia: ";
    getline(cin, materia);
    cout <<"Sección: ";
    getline(cin, seccion);
    cout <<"NRC: ";
    getline(cin,nrc);

    grupos[contadorGrupos].setMateria(materia);
    grupos[contadorGrupos].setSeccion(seccion);
    grupos[contadorGrupos].setNrc(nrc);
    ++contadorGrupos;
}

void Horario::editarGrupo()
{
    //Este método deberá mostrar la materia, sección y nrc de cada grupo y solicitarle
    //al usuario que seleccione uno para ser editado. Una vez seleccionado
    //un grupo se deberá llamar al método menú de ese grupo particular.
    int opc;
    cout <<"                        Editar Grupo" <<endl <<endl;
    if(contadorGrupos>0)
    {
        for (int i(0); i < contadorGrupos; ++i)
        {
            cout <<i+1 <<") " <<grupos[i].getMateria() <<" | " << grupos[i].getSeccion()
             << " | " << grupos[i].getNrc() << " | " << grupos[i].getEstudiantesCount()
              << " estudiantes registrados" << endl;
        }
        cout <<"0) Cancelar" <<endl
            <<"Selecciona una opción: ";
        cin >>opc;

        if (0 < opc && opc <= contadorGrupos)
        {
            grupos[opc-1].menu();
        }
        else
        {
            cout <<"Regresando al menú principal" <<endl;
        }
    }
    else
    {
        cout << "No hay grupos registrados" << endl;
    }
}

void Horario::mostrarGrupos()
{
    //Este método deberá mostrar la materia, sección, nrc y cantidad de estudiantes de
    //cada grupo.
    cout <<"                        Mis Grupos" <<endl <<endl;
    for (int i(0); i < contadorGrupos; ++i)
    {
            cout << i+1 << ") " << grupos[i].getMateria() << " | "
                << grupos[i].getSeccion() << " | " << grupos[i].getNrc() << " | "
                    << grupos[i].getEstudiantesCount() << " estudiantes registrados" << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
    }
}

void Horario::buscarGrupo()
{
    //Este método deberá buscar por coincidencia de patrones el nombre de una
    //materia dentro de todos los grupos registrados y mostrar aquellos en los que
    //coincida el patrón.
    string patron;
    int coincidencias = 0;

    cout <<"                        Buscar Grupo" <<endl <<endl
        <<"Nombre: ";
    getline(cin, patron);
    for (int i(0); i < this->contadorGrupos ; ++i)
    {
        if (grupos[i].getMateria().find(patron, 0) < grupos[i].getMateria().size())
        {
            cout << ++coincidencias << ") " << grupos[i].getMateria() << " | "
            << grupos[i].getSeccion() << " | " << grupos[i].getNrc() << " | "
            << grupos[i].getEstudiantesCount() << " estudiantes registrados" << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
        }
    }
    if (coincidencias == 0)
    {
        cout <<"No se encontraron coincidencias" <<endl;
    }
}

void Horario::menu()
{
    int opc;
    do
    {
        cout <<"                        Ciclo Escolar " <<cicloEscolar <<endl <<endl
            <<OPC_AGREGAR_GRUPO <<") Agregar grupo" <<endl
           <<OPC_EDITAR_GRUPO <<") Editar grupo" <<endl
          <<OPC_MOSTRAR_GRUPOS <<") Mostrar grupos" <<endl
         <<OPC_BUSCAR_GRUPO <<") Buscar grupo" <<endl
        <<OPC_SALIR_HORARIO <<") Salir" <<endl
        <<"Selecciona una opción: ";
        cin >>opc;
        cin.ignore();

        switch (opc)
        {
        case OPC_AGREGAR_GRUPO:
            if (contadorGrupos < MAX_GRUPO)
            {
                agregarGrupo();
            }
            else
            {
                cout <<"No se pueden agregar más grupos" <<endl;
            }
            break;
        case OPC_EDITAR_GRUPO:
            if (contadorGrupos > 0)
            {
                editarGrupo();
            }
            else
            {
                cout <<"No hay grupos registrados" <<endl;
            }
            break;
        case OPC_MOSTRAR_GRUPOS:
            if (contadorGrupos > 0)
            {
                mostrarGrupos();
            }
            else
            {
                cout <<"No hay grupos registrados" <<endl;
            }
            break;
        case OPC_BUSCAR_GRUPO:
            if (contadorGrupos > 0)
            {
                buscarGrupo();
            }
            else
            {
                cout <<"No hay grupos registrados" <<endl;
            }
            break;
        case OPC_SALIR_HORARIO:
            cout <<"Saliendo de la aplicación." <<endl;
            break;
        default:
            cout <<"Opción no válida" <<endl;
            break;
        }
    }
    while(opc != OPC_SALIR_HORARIO);
}
