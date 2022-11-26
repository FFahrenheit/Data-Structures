#include <iostream>

using namespace std;

double factorial(int *);

int main()
{
    int numero;
    int * ptr1 = NULL;
    cout << "Ingrese el numero a obtener factorial:" << endl;
    cin >> numero;
    ptr1 = &numero;
    cout << "El factorial de " << numero << " es " << factorial(ptr1);
    return 0;
}

double factorial(int * n)
{
    double acc = 1;
    double * result = & acc;
    for(int i= 1; i<= *n ; i++)
    {
        *result = *result * i;
    }
    return *result; //Valor de lo que almacena
}
