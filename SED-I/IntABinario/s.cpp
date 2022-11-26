#include <iostream>
#include <cstdlib>

int * ptr = NULL;
int n;

void to_binary(int*);
void convertToBinary(int n);


using namespace std;

int main()
{
    cout << "Ingrese un numero: ";
    cin >> n;
    ptr = &n;
    cout << "En binario es: ";
    to_binary(ptr);
    return 0;
}

void to_binary(int * n)
{
    int * cociente = (int*)malloc(sizeof(int));
    int * residuo = (int*)malloc(sizeof(int));
    *residuo = *n % 2;
    *cociente = *n / 2;
    if(*cociente != 0)
    {
        to_binary(cociente);
    }
    cout << *residuo;
    free(cociente);
    free(residuo);
}
