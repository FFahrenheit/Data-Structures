//
// Created by ivan_ on 12/11/2020.
//

#include "Tienda.h"

Tienda::Tienda()
{
    productos = ListaEstatica<Producto>(); //No maximo predefinido
    isSorted = false;
    nombreTienda = "Abarrotes pan-demicos";
}

Tienda::~Tienda()
{
    productos.clear();
}

void Tienda::agregarProducto()
{
    Producto p;
    string nombre;
    float precio;
    int existencia;
    cout << "Ingrese el nombre del producto: ";
    getline(cin,nombre);
    p.setNombre(nombre);
    cout << "Ingrese el precio del producto: $";
    cin >> precio;
    p.setPrecio(precio);
    cout << "Ingrese la existencia del producto: ";
    cin >> existencia;
    p.setExistencia(existencia);
    productos.push_back(p);

    cout << "Producto agregado" << endl;
}

void Tienda::consultarProductos()
{
    if(productos.empty())
    {
        cout << "No hay productos en la base de datos" << endl;
    }
    else
    {
        cout << endl;
        for(size_t i(0); i<productos.size();++i)
        {
            cout << "* * * * * * * * * * * * * * * * * * * * \n";
            cout << "Nombre: " << productos[i].getNombre() << endl <<
                        "Precio: $" << productos[i].getPrecio() << endl <<
                            "Existencia: " << productos[i].getExistencia() << endl;
        }
        cout << endl;
    }
}

bool Tienda::buscarProducto(const string &nombre)
{
    Producto p;
    p.setNombre(nombre);
    return isSorted ?
        binarySearch(productos,p) != productos.size() :
        sequentialSearch(productos,p) != productos.size();
}

void Tienda::getProducto(const string & nombre)
{
    Producto p;
    p.setNombre(nombre);
    if(buscarProducto(nombre))
    {
        size_t index = isSorted ? binarySearch(productos,p) : sequentialSearch(productos,p);
        cout << "Producto encontrado: " << endl;
        cout << "Nombre: " << productos[index].getNombre() << endl <<
                    "Precio: $" << productos[index].getPrecio() << endl <<
                        "Existencia: " << productos[index].getExistencia() << endl;
    }
    else
    {
        cout << "No se encuentra el producto en la base de datos" << endl;
    }
}

void Tienda::ordenarProductos()
{
    if(productos.size()<10)  //Para listas pequeñas, inserción es muy rápido, aunque 10 tampcoo es "muy grande"
    {
        insertionSort(productos);
    }
    else
    {
        quickSort(productos);
    }
    cout << "Productos ordenados" << endl;
}

void Tienda::guardarProductos()
{
    cout << "Esta opcion reescribira la base de datos del archivo" << endl;
    fstream archivo;
    archivo.open(filename, ios::out);

    if(!archivo.is_open())
    {
        cout << "No se pudieron guardar los datos" << endl;
    }
    else
    {
        for(size_t i(0); i<productos.size(); i++)
        {
            archivo << productos[i];
        }
        cout << "Se han guardado los productos actuales en el archivo" <<endl;
        archivo.close(); //Si no se abrió para qué cerrarlo
    }
}

void Tienda::cargarProductos()
{
    cout << "Esta opcion reemplazara la base de datos local" << endl;
    fstream archivo;

    archivo.open(filename,ios::in);

    if(!archivo.is_open())
    {
        cout << "No se pudieron cargar los datos" << endl;
    }
    else
    {
        productos.clear();
        Producto p;
        while(archivo >> p)
        {
            productos.push_back(p);
        }
        archivo.close();
        cout << "Se han cargado " << productos.size() << " productos" << endl;
    }
}

void Tienda::menu() {
    int opc;
    do
    {
        cout << "\n\t\tMenu para " << nombreTienda << endl;
        cout << OPC_AGREGAR << ") Agregar producos" << endl
                << OPC_CONSULTAR << ") Consultar productos" << endl <<
                    OPC_BUSCAR << ") Buscar producto" << endl <<
                        OPC_ORDERNAR << ") Ordenar productos" << endl <<
                            OPC_GUARDAR << ") Guardar productos" << endl <<
                                OPC_CARGAR << ") Cargar productos" << endl <<
                                    OPC_SALIR << ") Salir" << endl;
        cout << "Ingrese su eleccion: ";
        cin >> opc;
        cin.clear();
        cin.ignore();
        switch(opc)
        {
            case OPC_AGREGAR:
                agregarProducto();
                break;
            case OPC_CONSULTAR:
                consultarProductos();
                break;
            case OPC_BUSCAR:
            {
                string nombre;
                cout << "Ingrese el producto a buscar: ";
                getline(cin,nombre);
                getProducto(nombre);
                break;
            }
            case OPC_ORDERNAR:
                ordenarProductos();
                break;
            case OPC_GUARDAR:
                guardarProductos();
                break;
            case OPC_CARGAR:
                cargarProductos();
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
            case OPC_SALIR:
                cout << "Gracias por visitar el sistema de " << nombreTienda << endl;
                break;
        }
    }while(opc != OPC_SALIR);
}
