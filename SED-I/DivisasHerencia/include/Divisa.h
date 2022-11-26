#ifndef DIVISA_H
#define DIVISA_H


class Divisa
{
    protected:
        float valorDolar;
    public:
        float getValorDolar();
        void setValorDolar(float);
        float getFromDolar(float);
        float getFromPeso(float);
        float getFromYen(float);
        float getFromEuro(float);
        float getFromYuan(float);
        float getToDolar(float);
        float getToPeso(float);
        float getToYen(float);
        float getToEuro(float);
        float getToYuan(float);
};

#endif // DIVISA_H
