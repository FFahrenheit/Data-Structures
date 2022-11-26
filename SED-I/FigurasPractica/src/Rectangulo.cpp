#include "Rectangulo.h"

Rectangulo::Rectangulo()
{
    this->altura=0;
    this->base=0;
}

void Rectangulo::setAltura(double altura)
{
    this->altura = altura;
}

void Rectangulo::setBase(double base)
{
    this->base = base;
}

void Rectangulo::calcularArea()
{
    this->area = this->base * this->altura;
}

double Rectangulo::getAltura()
{
    return this->altura;
}

double Rectangulo::getBase()
{
    return this->base;
}

double Rectangulo::getArea()
{
    return this->area;
}
