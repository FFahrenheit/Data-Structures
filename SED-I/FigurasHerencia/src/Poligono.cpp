#include "Poligono.h"

void Poligono::calcularArea()
{
    this->area = this->base *this->lados * this->altura / 2;
}

void Poligono::setLados(int l)
{
    this->lados = l;
}

int Poligono::getLados()
{
    return this->lados;
}
