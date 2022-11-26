#ifndef KELVIN_H
#define KELVIN_H


class Kelvin
{
    private:
            double value;
    public:
        Kelvin();
        void setTemperature(double);
        double getTemperature();
        double toCelsius();
        double toFahrenheit();
};

#endif // KELVIN_H
