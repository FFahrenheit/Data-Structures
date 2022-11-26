#include "Grupo.h"

//En el constructor damos valor inicial a los atributos del grupo
Grupo::Grupo()
{
    materia = "-";
    seccion = "-";
    nrc = "-";
    contadorEstudiantes = 0;
}

void Grupo::setMateria(const string &valor)
{
    this->materia = valor;
}

string Grupo::getMateria() const
{
    return materia;
}

void Grupo::setSeccion(const string &valor)
{
    this->seccion = valor;
}

string Grupo::getSeccion() const
{
    return seccion;
}

void Grupo::setNrc(const string &valor)
{
    this->nrc = valor;
}

string Grupo::getNrc() const
{
    return nrc;
}

void Grupo::agregarEstudiante()
{
    //Creamos un objeto tipo estudiante
    Estudiante e;
    //Variables para los atributos del objeto tipo estudiante
    string nombre;
    string carrera;
    string codigo;

    //Solicitamos al usuario que ingrese los valores
    cout <<"Nombre: ";
    getline(cin, nombre);
    cout <<"Carrera: ";
    getline(cin, carrera);
    cout <<"C�digo: ";
    getline(cin, codigo);

    //Asignamos los valores al estudiante haciendo uso de los m�todos de interfaz.
    e.setNombre(nombre);
    e.setCodigo(codigo);
    e.setCarrera(carrera);

    //Asignamos el estudiante creado al arreglo en la posici�n indicada por el contador.
    estudiantes[contadorEstudiantes] = e;
    //Aumentamos el contador de estudiantes del grupo.
    contadorEstudiantes++;
}

void Grupo::consultarEstudiante(const Estudiante &e) const
{
    cout <<"Nombre: " <<e.getNombre() <<endl
        <<"Carrera: " <<e.getCarrera() <<endl
       <<"C�digo: " <<e.getCodigo() <<endl;
}

void Grupo::consultarLista() const
{
    for (int i = 0; i < contadorEstudiantes; ++i)
    {
        consultarEstudiante(estudiantes[i]);
        cout <<"~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" <<endl;
    }
}

void Grupo::buscarEstudiante() const
{
    string patron;
    int contador = 0;
    cout <<"Nombre a buscar: ";
    getline(cin, patron);
    //Revisamos cada estudiante del arreglo
    for (int i = 0; i < contadorEstudiantes; ++i)
    {
        //Realizamos b�squeda por coincidencia de patrones en el nombre de cada estudiante.
        //find(qu� Busco, a partir de donde)
        if (estudiantes[i].getNombre().find(patron, 0) < estudiantes[i].getNombre().size())
        {
            consultarEstudiante(estudiantes[i]);
            cout <<"~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" <<endl;
            ++contador;
        }
    }
    //En caso de no encontrar estudiantes mostramos un mensaje correspondiente.
    if (contador == 0)
    {
        cout <<"No se encontr� el patr�n buscado" <<endl <<endl;
    }
}

void Grupo::modificarEstudiante()
{
    string codigo;
    int i;
    cout <<"C�digo del estudiante: ";
    getline(cin, codigo);

    for (i = 0; i < contadorEstudiantes; ++i)
    {
        if (estudiantes[i].getCodigo() == codigo)
        {
            string nombre;
            string carrera;
            string codigo;

            cout <<"Datos del estudiante" <<endl;
            consultarEstudiante(estudiantes[i]);
            cout <<"Ingresa los nuevo datos" <<endl
                <<"Nombre: ";
            getline(cin, nombre);
            cout <<"Carrera: ";
            getline(cin, carrera);
            cout <<"C�digo: ";
            getline(cin, codigo);

            estudiantes[i].setNombre(nombre);
            estudiantes[i].setCarrera(carrera);
            estudiantes[i].setCodigo(codigo);

            cout <<"Estudiante modificado con �xito" <<endl <<endl;
            break;
        }
    }
    if (i == contadorEstudiantes)
    {
        cout <<"No se encontr� el c�digo" <<endl <<endl;
    }
}

void Grupo::menu()
{
    int opc;

    do
    {
        cout <<"                        Men� para " <<materia <<" "
            <<seccion <<endl <<endl
           <<OPC_AGREGAR <<") Agregar estudiante" <<endl
          <<OPC_CONSULTAR <<") Consultar estudiantes" <<endl
         <<OPC_BUSCAR <<") Buscar estudiante" <<endl
        <<OPC_MODIFICAR <<") Modificar estudiante" <<endl
        <<OPC_SALIR <<") Salir" <<endl <<endl;
        cout <<"Selcciona una opci�n: ";
        cin >>opc;
        cin.ignore();

        switch (opc)
        {
        case OPC_AGREGAR:
            cout <<"                        Agregar Estudiante" <<endl;
            if (contadorEstudiantes < MAX_ESTUDIANTE)
            {
                agregarEstudiante();
                cout <<"Estudiante agregado con �xito." <<endl <<endl;
            }
            else
            {
                cout <<"No hay cupos disponibles." <<endl <<endl;
            }
            break;
        case OPC_CONSULTAR:
            cout <<"                        Consultar Estudiantes" <<endl;
            if (contadorEstudiantes > 0)
            {
                consultarLista();
            }
            else
            {
                cout <<"No hay estudiantes registrados." <<endl <<endl;
            }
            break;
        case OPC_BUSCAR:
            if (contadorEstudiantes > 0)
            {
                cout <<"                    B�squeda de Estudiantes" <<endl;
                buscarEstudiante();
            }
            else
            {
                cout <<"No hay estudiantes registrados." <<endl <<endl;
            }
            break;
        case OPC_MODIFICAR:
            if (contadorEstudiantes > 0)
            {
                cout <<"                    Modificar Estudiante" <<endl;
                modificarEstudiante();
            }
            else
            {
                cout <<"No hay estudiantes registrados." <<endl <<endl;
            }
            break;
        case OPC_SALIR:
            cout <<"Saliendo del grupo" <<endl;
            break;
        default:
            cout <<"Opci�n no v�lida" <<endl;
            break;
        }
    }
    while(opc != OPC_SALIR);
}

int Grupo::getEstudiantesCount()
{
    return this->contadorEstudiantes;
}

