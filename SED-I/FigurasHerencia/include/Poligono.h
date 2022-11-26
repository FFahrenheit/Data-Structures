#ifndef POLIGONO_H
#define POLIGONO_H

#include "Figura.h"

class Poligono : public Figura
{
    private:
        int lados;
    public:
        void calcularArea();
        void setLados(int);
        int getLados();
};

#endif // POLIGONO_H
