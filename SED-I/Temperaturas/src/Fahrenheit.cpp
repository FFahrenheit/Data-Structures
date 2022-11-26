#include "Fahrenheit.h"

Fahrenheit::Fahrenheit()
{
    this->value = 0;
}

void Fahrenheit::setTemperature(double temperature)
{
    this->value = temperature;
}

double Fahrenheit::getTemperature()
{
    return this->value;
}

double Fahrenheit::toCelsius()
{
    return (this->value-32)*5/9;
}

double Fahrenheit::toKelvin()
{
     return (this->value - 32) * 5/9 + 273.15;
}
