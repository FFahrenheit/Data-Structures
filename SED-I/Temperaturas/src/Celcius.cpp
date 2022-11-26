#include "Celsius.h"

Celsius::Celsius()
{
    this->value = 0;
}

void Celsius::setTemperature(double temperature)
{
    this->value = temperature;
}

double Celsius::getTemperature()
{
    return this->value;
}

double Celsius::toFahrenheit()
{
    return (this->value)*9/5 + 32;
}

double Celsius::toKelvin()
{
     return this->value + 273.15;
}
