#include "Triangulo.h"

Triangulo::Triangulo()
{
    this->altura=0;
    this->base=0;
}

void Triangulo::setAltura(double altura)
{
    this->altura = altura;
}

void Triangulo::setBase(double base)
{
    this->base = base;
}

void Triangulo::calcularArea()
{
    this->area = this->base * this->altura / 2;
}

double Triangulo::getAltura()
{
    return this->altura;
}

double Triangulo::getBase()
{
    return this->base;
}

double Triangulo::getArea()
{
    return this->area;
}
