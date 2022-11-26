#ifndef CUADRADO_H
#define CUADRADO_H


class Cuadrado
{
    private:
        double base;
        double altura;
        double area;
    public:
        Cuadrado();
        void setBase(double);
        void setAltura(double);
        void calcularArea();
        double getBase();
        double getAltura();
        double getArea();
};

#endif // CUADRADO_H
