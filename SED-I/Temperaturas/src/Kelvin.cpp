#include "Kelvin.h"

Kelvin::Kelvin()
{
    this->value = 0;
}

void Kelvin::setTemperature(double temperature)
{
    this->value = temperature;
}

double Kelvin::getTemperature()
{
    return this->value;
}

double Kelvin::toCelsius()
{
    return (this->value)-273.15;
}

double Kelvin::toFahrenheit()
{
     return (this->toCelsius()) *9/5 + 32;
}
