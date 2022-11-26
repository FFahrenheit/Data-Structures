#ifndef FIGURA_H
#define FIGURA_H


class Figura
{
    protected:
        double base;
        double altura;
        double area;
    public:
        double getBase();
        double getAltura();
        void setBase(double);
        void setAltura(double);
        virtual void calcularArea();
        double getArea();
};

#endif // FIGURA_H
