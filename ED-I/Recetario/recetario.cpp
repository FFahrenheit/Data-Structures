#include <iostream>

using namespace std;


const int MAX_INGREDIENTE = 10;
const int MAX_PASO = 20;
const int MAX_RECETA = 5;
int contadorReceta;

union Cantidad
{
    int gramos;
    float kilos;
    int mililitros;
    float litros;
};

struct Ingrediente
{
    string nombre;
    Cantidad cantidad;
    int unidadMedida;
};

enum Unidades
{
    U_GRAMO = 1,
    U_KILO,
    U_MILILITRO,
    U_LITRO
};

enum Opciones
{
    OPC_SALIR,
    OPC_AGREGAR,
    OPC_CONSULTAR,
    OPC_BUSCAR
};

struct Receta
{
    string nombre;    //Nombre de la receta
    Ingrediente ingredientes[MAX_INGREDIENTE];    //Arreglo de ingredientes
    int contador;    //Contador de ingredientes registrados
    int contadorPasos;    //Contador de pasos (instrucciones) registrados
    string pasos[MAX_PASO];    //Arreglo de pasos (instrucciones)
};

enum OpcionesReceta
{
    RCT_SALIR,
    RCT_AGREGAR,
    RCT_CONSULTAR,
    RCT_BUSCAR,
    RCT_AGREGAR_PASO,
    RCT_CONSULTAR_PASO
};

Receta recetario[MAX_RECETA];

//Prototipos
//Idealmente el primer procedimiento implementado deber ser el main, por ello
//declaramos los prototipos antes de implementarlos
void registrarIngrediente(Ingrediente &ingrediente);
void consultarIngrediente(const Ingrediente &ingrediente);
void buscarIngrediente(const Receta &receta);

void menu(Receta &receta);
void menuRecetario();

void registrarReceta(Receta &receta);
void consultarReceta(const Receta &receta);
void buscarReceta();

int main()
{

    contadorReceta = 0;
    menuRecetario();

    return 0;
}

void registrarIngrediente(Ingrediente& ingrediente)
{
    cout <<"Nombre: ";
    getline(cin, ingrediente.nombre); //Solicitamos el nombre del ingrediente
    do
    {
        //Debemos seleccionar la unidad en que se registrará el ingrediente
        cout <<"En que unidad se registrara el ingrediente? " <<endl
            <<U_GRAMO <<") Gramos" <<endl
           <<U_KILO <<") Kilos" <<endl
          <<U_MILILITRO <<") Mililitros" <<endl
         <<U_LITRO <<") Litros" <<endl
        <<"Selecciona una opcion: ";
        cin >>ingrediente.unidadMedida;
    }
    while(ingrediente.unidadMedida < U_GRAMO || ingrediente.unidadMedida > U_LITRO);
    //Solicitaremos el dato mientras sea incorrecto

    cout <<"Cantidad: ";
    //Solicitamos la cantidad según la unidad correspondiente
    switch (ingrediente.unidadMedida)
    {
    case U_GRAMO:
        cin >>ingrediente.cantidad.gramos;
        break;
    case U_KILO:
        cin >>ingrediente.cantidad.kilos;
        break;
    case U_MILILITRO:
        cin >>ingrediente.cantidad.mililitros;
        break;
    case U_LITRO:
        cin >>ingrediente.cantidad.litros;
        break;
    default:
        break;
    }
}

//Recibe una referencia constante, es decir que a pesar de recibir una referencia
//no puede ser modificada
void consultarIngrediente(const Ingrediente& ingrediente)
{
    cout <<"Nombre: " <<ingrediente.nombre <<endl
        <<"Cantidad: ";
    //La cantidad debe ser consultada según la unidad en que fue guardada
    switch (ingrediente.unidadMedida)
    {
    case U_GRAMO:
        cout <<ingrediente.cantidad.gramos <<" grs" <<endl;
        break;
    case U_KILO:
        cout <<ingrediente.cantidad.kilos <<" kilos" <<endl;
        break;
    case U_MILILITRO:
        cout <<ingrediente.cantidad.mililitros <<" mls" <<endl;
        break;
    case U_LITRO:
        cout <<ingrediente.cantidad.litros <<" lts" <<endl;
        break;
    default:
        break;
    }
}

void buscarIngrediente(const Receta& receta)
{
    string patron;
    int i;
    int coincidencias = 0;

    cout <<"Busqueda: ";
    getline(cin, patron);

    cout << endl;

    for(int i=0; i<receta.contador; i++)
    {
        if(receta.ingredientes[i].nombre.find(patron,0) < receta.ingredientes[i].nombre.size())
        {
            coincidencias++;
            consultarIngrediente(receta.ingredientes[i]);
            cout << "---\t---\t---\t---\t---" << endl;;
        }
    }

    if (coincidencias == 0)
    {
        cout <<"No se encontro el ingrediente" <<endl;
    }
    else 
    {
        cout << "Total de coincidencias: "<< coincidencias << endl;;
    }
}

void menu(Receta &receta)
{
    int opc;
    do
    {
        cout << "\t\t\tMenu para " << receta.nombre << endl;;
        cout << RCT_AGREGAR << ") Agregar ingrediente" << endl;
        cout << RCT_CONSULTAR << ") Consultar ingrediente" << endl;
        cout << RCT_BUSCAR << ") Buscar ingrediente" << endl;
        cout << RCT_AGREGAR_PASO << ") Agregar paso" << endl;
        cout << RCT_CONSULTAR_PASO << ") Consultar pasos" << endl;
        cout << RCT_SALIR << ") Salir" << endl;
        cout << "Selecciona una opcion: ";

        cin >> opc;
        cin.ignore();

        switch (opc)
        {
            case RCT_AGREGAR:
                cout << "\t\t\tRegistro de ingrediente"<<endl;
                if(receta.contador < MAX_INGREDIENTE)
                {
                    registrarIngrediente(receta.ingredientes[receta.contador++]);
                }
                else 
                {
                    cout << "No hay mas espacio para ingredientes" << endl;
                }
                break;

            case RCT_CONSULTAR:
                cout << "\t\t\tIngredientes registrados" << endl;;
                if(receta.contador == 0)
                {
                    cout << "No hay ingredientes para esta receta aun" << endl;
                }
                else
                {
                    for(int i=0; i<receta.contador; i++)
                    {
                        consultarIngrediente(receta.ingredientes[i]);
                        cout << "---\t---\t---\t---\t---" << endl;;
                    }
                    cout << "Total de ingredientes: " << receta.contador << endl;
                }
                break;

            case RCT_BUSCAR:
                cout << "\t\t\tBusqueda de ingredientes"<<endl;
                buscarIngrediente(receta);
                break; 

            case RCT_AGREGAR_PASO:
                cout << "\t\t\tRegistro de ingrediente"<<endl;
                if(receta.contadorPasos < MAX_PASO)
                {
                    cout << "Paso: " << receta.contadorPasos+1<<endl; 
                    cout << "Descripcion: ";
                    getline(cin, receta.pasos[receta.contadorPasos++]);
                }
                else 
                {
                    cout << "No hay mas espacio para pasos" << endl;
                }
                break;

            case RCT_CONSULTAR_PASO:
                cout << "\t\t\tConsultar pasos" << endl; 
                if(receta.contadorPasos == 0)
                {
                    cout << "No hay pasos registrados aun";
                }
                else 
                {
                    cout << "Pasos: "<<endl;
                    for(int i=0; i<receta.contadorPasos; i++)
                    {
                        cout << i+1 << ". ";
                        cout << receta.pasos[i] << endl;
                    }
                    cout << endl << "Total de pasos: " << receta.contadorPasos;
                }
                break;
            case RCT_SALIR:
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    } while (opc!= RCT_SALIR);
}

void registrarReceta(Receta &receta)
{
    cout << "Nombre: ";
    getline(cin, receta.nombre);
    menu(receta);
}

void consultarReceta(const Receta &receta)
{
    cout << "\t\t\t" << receta.nombre << endl << endl; 
    cout << "Ingredientes: " << endl;
    for(int i=0; i<receta.contador;i++)
    {
        consultarIngrediente(receta.ingredientes[i]);
    }
    cout << "Pasos:"<<endl;
    for(int i=0; i<receta.contadorPasos; i++)
    {
        cout << i+1 << ". " << receta.pasos[i] << endl;
    }
}

void buscarReceta()
{
    string patron;
    int i;
    int coincidencias = 0;

    cout <<"Busqueda: ";
    getline(cin, patron);
    cout << endl; 

    for(int i=0; i<contadorReceta; i++)
    {
        Receta receta = recetario[i];
        if(receta.nombre.find(patron,0) < receta.nombre.size())
        {
            coincidencias++;
            consultarReceta(receta);
            cout << "---\t---\t---\t---\t---" << endl;;
        }
    }

    if (coincidencias == 0)
    {
        cout <<"No se encontraron recetas" <<endl;
    }
    else 
    {
        cout << "Total de coincidencias: "<< coincidencias << endl;;
    }
}

void menuRecetario()
{
    int opc;
    do
    {
        cout << "\t\t\tRECETARIO"<<endl<<endl;
        cout << OPC_AGREGAR << ") Agregar Receta" << endl;
        cout << OPC_CONSULTAR << ") Consultar Recetas" << endl;
        cout << OPC_BUSCAR << ") Buscar Receta" << endl;
        cout << OPC_SALIR << ") Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opc; 
        cin.ignore();
        switch(opc)
        {
            case OPC_AGREGAR:
                cout <<"\t\t\tRegistro de receta" <<endl;
                if (contadorReceta < MAX_INGREDIENTE)
                {
                    registrarReceta(recetario[contadorReceta]);
                    contadorReceta++;
                }
                else
                {
                    cout <<"No hay espacio para más recetas" <<endl;
                }
                break;

            case OPC_CONSULTAR:
                cout << "\t\t\tConsulta de recetas" << endl;
                if(contadorReceta == 0)
                {
                    cout << "Aun no hay recetas registradas" << endl;
                }
                else 
                {
                    for(int i=0; i<contadorReceta; i++)
                    {
                        consultarReceta(recetario[i]);
                    }
                    cout << "Total de recetas: " << contadorReceta;
                }
                break; 

            case OPC_BUSCAR:
                cout << "\t\t\tBuscar recetas"<<endl;
                buscarReceta();
                break;

            case OPC_SALIR:
                cout << "Gracias por usar mi recetario" << endl; 
                system("pause");
                break;

            default:
                cout << "Ingrese una opcion valida" << endl;
                break;

        }  
    } while (opc!=OPC_SALIR);
}