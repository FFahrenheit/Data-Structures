#include <iostream>

using namespace std;

void incrementa(int *a)
{

    (*a)++;
}

int main()

{
    int* numero = new int(33);

    cout <<"Antes" <<endl <<"*numero: " <<*numero <<endl; incrementa(numero);

    cout <<"Después" <<endl <<"*numero: " <<*numero <<endl; return 0;

}


