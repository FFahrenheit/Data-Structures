#ifndef PILA_H
#define PILA_H

template <class T>
class Pila
{
    private:
        struct Nodo
        {
            T dato;
            Nodo * sig;
            Nodo(T _dato) : dato(_dato){};
        }*tope,*aux;
    public:
        Pila();
        void push(T);
        void pop();
        T getTope();
        bool vacia();
        ~Pila();
};

#endif // PILA_H
