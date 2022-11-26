//
// Created by ivan_ on 25/03/2021.
//

#ifndef PROGRAMA02_CASA_H
#define PROGRAMA02_CASA_H

#include <iostream>

using namespace std;

class Casa {
private:
    int numero;
    string calle;
    string propietario;
public:
    Casa(int numero, const string &calle, const string &propietario);
    Casa();

    int getNumero() const;
    void setNumero(int numero);

    const string &getCalle() const;
    void setCalle(const string &calle);

    const string &getPropietario() const;
    void setPropietario(const string &propietario);

    bool operator==(const Casa &rhs) const;
    bool operator!=(const Casa &rhs) const;

    bool operator<(const Casa &rhs) const;
    bool operator>(const Casa &rhs) const;

    friend ostream& operator <<(ostream& os, const Casa& casa);
    friend istream& operator >>(istream& is, Casa& casa);

};


#endif //PROGRAMA02_CASA_H
