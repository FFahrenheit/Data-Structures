#include "Divisa.h"

void Divisa::setValorDolar(float valor)  //Cantidad de M.N que hacen un dolar
{
    this->valorDolar = valor;
}

float Divisa::getValorDolar()
{
    return this->valorDolar;
}

float Divisa::getFromDolar(float dolar)
{
    return valorDolar * dolar;
}

float Divisa::getFromYuan(float yuan)
{
    return valorDolar * yuan / 6.79;
}

float Divisa::getFromPeso(float peso)
{
    return valorDolar * peso / (21.37);
}

float Divisa::getFromYen(float yen)
{
    return valorDolar * yen / (105.64);
}

float Divisa::getFromEuro(float euro)
{
    return valorDolar * euro / (0.85);
}

float Divisa::getToDolar(float value)
{
    return value / valorDolar;
}

float Divisa::getToPeso(float value)
{
    return value / this->valorDolar * 21.37;
}

float Divisa::getToYen(float value)
{
    return value / this->valorDolar * 105.66;
}

float Divisa::getToEuro(float value)
{
    return value / this->valorDolar * 0.85;
}

float Divisa::getToYuan(float value)
{
    return value / this->valorDolar * 6.79;
}
