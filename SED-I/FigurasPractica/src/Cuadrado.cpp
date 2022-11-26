#include "Cuadrado.h"

Cuadrado::Cuadrado()
{
    this->altura=0;
    this->base=0;
}

void Cuadrado::setAltura(double altura)
{
    this->altura = altura;
}

void Cuadrado::setBase(double base)
{
    this->base = base;
}

void Cuadrado::calcularArea()
{
    this->area = this->base * this->altura;
}

double Cuadrado::getAltura()
{
    return this->altura;
}

double Cuadrado::getBase()
{
    return this->base;
}

double Cuadrado::getArea()
{
    return this->area;
}
