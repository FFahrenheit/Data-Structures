#include <iostream>
#include "Peso.h"
#include "Dolar.h"
#include "Yen.h"
#include "Yuan.h"
#include "Euro.h"
#include "Validador.h"

using namespace std;

int main()
{
    Validador val;
    Dolar dolar;
    Peso peso;
    Euro euro;
    Yen yen;
    Yuan yuan;
    int opc;
    do
    {
        string input;
        float value;
        system("cls");
        cout << "1) Peso-Dolar" << endl;
        cout << "2) Dolar-Peso" << endl;
        cout << "3) Peso-Euro" << endl;
        cout << "4) Euro-Peso" << endl;
        cout << "5) Peso-Yen" << endl;
        cout << "6) Yen-Peso" << endl;
        cout << "7) Peso-Yuan" << endl;
        cout << "8) Yuan-Peso" << endl;
        cout << "9) Salir" << endl;
        opc = val.requestInt("Ingrese una opcion: ");
        if(opc>=1 && opc<=8)
        {
            value = val.requestFloat("Ingrese el valor a convertir: ");
        }
        switch(opc)
        {
            case 1:
                cout << value << " pesos = " << peso.getToDolar(value) << " dolares" << endl;
                break;
            case 2:
                cout << value << " dolares = " << dolar.getToPeso(value) << " pesos" << endl;
                break;
            case 3:
                cout << value << " pesos = " << peso.getToEuro(value) << " euros" << endl;
                break;
            case 4:
                cout << value << " euros = " << euro.getToPeso(value) << " pesos" << endl;
                break;
            case 5:
                cout << value << " pesos = " << peso.getToYen(value) << " yen" << endl;
                break;
            case 6:
                cout << value << " yen = " << yen.getToPeso(value) << " pesos" << endl;
                break;
            case 7:
                cout << value << " pesos = " << peso.getToYuan(value) << " yanes" << endl;
                break;
            case 8:
                cout << value << " yuanes = " << yuan.getToPeso(value) << " pesos" << endl;
                break;
            case 9:
                cout << "Adiooos" << endl;
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
        system("pause");
    }while(opc!=9);
    return 0;
}
