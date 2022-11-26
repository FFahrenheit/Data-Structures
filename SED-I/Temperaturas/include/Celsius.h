#ifndef Celsius_H
#define Celsius_H


class Celsius
{
    private:
            double value;
    public:
        Celsius();
        void setTemperature(double);
        double getTemperature();
        double toKelvin();
        double toFahrenheit();
};

#endif // Celsius_H
