//
// Created by ivan_ on 12/11/2020.
//

#ifndef TIENDA_PRODUCTO_H
#define TIENDA_PRODUCTO_H

#include <iostream>

using namespace std;

class Producto
{
private:
    /***
     * Propiedades
     */
    string nombre;
    float precio;
    int existencia;
public:
    /***
     * Getter, setters y constructor
     */
    Producto();
    ~Producto();
    const string &getNombre() const;
    void setNombre(const string &);
    float getPrecio() const;
    void setPrecio(float);
    int getExistencia() const;
    void setExistencia(int);

    /***
     * Sobrecarga de operadores
     */
    friend ostream& operator <<(ostream&, const Producto&);
    friend istream& operator >>(istream&, Producto&);
    bool operator == (const Producto&) const;
    bool operator > (const Producto&) const;
    bool operator < (const Producto&) const;
    bool operator <= (const Producto&) const;
    bool operator >= (const Producto&) const;
    bool operator != (const Producto&) const;

};

#endif //TIENDA_PRODUCTO_H
