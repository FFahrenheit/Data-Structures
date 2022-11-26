#ifndef TRIANGULO_H
#define TRIANGULO_H


class Triangulo
{
    private:
        double base;
        double altura;
        double area;
    public:
        Triangulo();
        void setBase(double);
        void setAltura(double);
        void calcularArea();
        double getBase();
        double getAltura();
        double getArea();
};

#endif // TRIANGULO_H
