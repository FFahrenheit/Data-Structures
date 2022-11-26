#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H


class Fahrenheit
{
    private:
            double value;
    public:
        Fahrenheit();
        void setTemperature(double);
        double getTemperature();
        double toCelsius();
        double toKelvin();
};

#endif // FAHRENHEIT_H
