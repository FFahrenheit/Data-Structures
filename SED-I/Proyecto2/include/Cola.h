#ifndef COLA_H
#define COLA_H

template<class T>
class Cola
{
    private:
        struct Nodo
        {
            T dato;
            Nodo * sig;
            Nodo(T _dato) : dato(_dato){};
        }*frente,*aux, *fin;
    public:
        Cola();
        void push(T);
        void pop();
        T getInicio();
        T getFin();
        bool vacia();
        ~Cola();
};

#endif // COLA_H
