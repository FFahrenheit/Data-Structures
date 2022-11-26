#include <iostream>
#include <stdlib.h>

using namespace std;

float * ptr1 = NULL;
float * ptr2 = NULL;
float a, b;

float * suma(float*,float*);
float * resta(float*,float*);
float * multiplicacion(float*,float*);
float * division(float*,float*);

int get_int(string);

int main()
{
    int opc;
    ptr1 = &a;
    ptr2 = &b;
    do
    {
        system("cls");
        cout << "   :::: MENU ::::" << endl;
        cout << "1) Suma" << endl;
        cout << "2) Resta" << endl;
        cout << "3) Multiplicacion" << endl;
        cout << "4) Division" << endl;
        cout << "5) Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        if(opc>=1 && opc<=4)
        {
            cout << "Ingrese un numero: ";
            cin >> a;
            cout << "Ingrese otro numero: ";
            cin >> b;
            float * res = NULL;
            switch(opc)
            {
                case 1:
                    res = suma(ptr1,ptr2);
                    break;
                case 2:
                    res = resta(ptr1,ptr2);
                    break;
                case 3:
                    res = multiplicacion(ptr1,ptr2);
                    break;
                case 4:
                    res = division(ptr1,ptr2);
                    break;
            }
            cout << * res << endl;
            free(res);
        }
        else if(opc!=5)
        {
            cout << "Ingrese una opcion valida" << endl;
        }
        else
        {
            cout << "Gracias por usar este programa" << endl;
        }
        system("pause");
    }while(opc != 5);
    return 0;
}

float * suma(float * a, float * b)
{
    float * res = (float*) malloc(sizeof(float));
    *res = (*a) + (*b);
    return res;
}

float * resta(float * a, float * b)
{
    float * res = (float*) malloc(sizeof(float));
    *res = (*a) - (*b);
    return res;
}

float * multiplicacion(float * a, float * b)
{
    float * res = (float*) malloc(sizeof(float));
    *res = (*a) * (*b);
    return res;
}

float * division(float * a, float * b)
{
    float * res = (float*) malloc(sizeof(float));
    *res = (*a) / (*b);
    return res;
}

