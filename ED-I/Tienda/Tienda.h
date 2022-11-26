//
// Created by ivan_ on 12/11/2020.
//

#ifndef TIENDA_TIENDA_H
#define TIENDA_TIENDA_H

#include <iostream>
#include <fstream>
#include "Producto.h"
#include "ListaEstatica.h"
#include "Algoritmos.h"

class Tienda {
public:
    Tienda();
    ~Tienda();
    void agregarProducto();
    void consultarProductos();
    void getProducto(const string&);
    void ordenarProductos();
    void guardarProductos();
    void cargarProductos();
    void menu();
private:
    bool buscarProducto(const string&);
    ListaEstatica<Producto> productos;
    bool isSorted;
    const string filename=  "productos.txt";
    string nombreTienda;

    enum Opciones
    {
        OPC_AGREGAR = 1,
        OPC_CONSULTAR,
        OPC_BUSCAR,
        OPC_ORDERNAR,
        OPC_GUARDAR,
        OPC_CARGAR,
        OPC_SALIR
    };
};

#endif //TIENDA_TIENDA_H
