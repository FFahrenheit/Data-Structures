#ifndef DATO_H
#define DATO_H

#include <iostream>

using namespace std;

class Dato
{
    public:
        Dato();
        virtual ~Dato();
        Dato(int,const string&,const string&,const string&);
        int getId() const;
        const string& getNombre() const;
        const string& getDireccion() const;
        const string& getMail() const;
        void setId(int);
        void setNombre(const string&);
        void setDireccion(const string&);
        void setMail(const string&);
        friend ostream& operator <<(ostream&, const Dato&);
        bool operator == (const Dato&) const;
        bool operator > (const Dato&) const;
        bool operator < (const Dato&) const;
        void imprimir() const;
    private:
        int id;
        string nombre;
        string direccion;
        string mail;
};

#endif // DATO_H
