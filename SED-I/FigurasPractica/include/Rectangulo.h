#ifndef RECTANGULO_H
#define RECTANGULO_H


class Rectangulo
{
    private:
        double base;
        double altura;
        double area;
    public:
        Rectangulo();
        void setBase(double);
        void setAltura(double);
        void calcularArea();
        double getBase();
        double getAltura();
        double getArea();
};

#endif // RECTANGULO_H
