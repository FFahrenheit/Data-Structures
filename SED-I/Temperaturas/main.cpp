#include <iostream>
#include "Fahrenheit.h"
#include "Kelvin.h"
#include "Celsius.h"

using namespace std;

int main()
{
    int opc;
    int temperature;
    Celsius celsius;
    Kelvin kelvin;
    Fahrenheit fahrenheit;
    do
    {
        cout << "\n\t\tMENU\n";
        cout << "1)Celsius a Kelvin\n";
        cout << "2)Kelvin a Celsius\n";
        cout << "3)Celsius a Fahrenheit\n";
        cout << "4)Fahrenheit a Celsius\n";
        cout << "5)Kelvin a Fahrenheit\n";
        cout << "6)Fahrenheit a Kelvin\n";
        cout << "7)Salir\n";
        cout << "Tu opcion: ";
        cin >> opc;
        if(opc>=1 && opc<=6)
        {
            cout << "Ingrese su temperatura: ";
            cin >> temperature;
        }
        switch(opc)
        {
            case 1:
                celsius.setTemperature(temperature);
                cout << celsius.getTemperature() << "°C = " << celsius.toKelvin() << "K\n";
                break;
            case 2:
                kelvin.setTemperature(temperature);
                cout << kelvin.getTemperature() << "K = " << kelvin.toCelsius() << "°C\n";
                break;
            case 3:
                celsius.setTemperature(temperature);
                cout << celsius.getTemperature() << "°C = " << celsius.toFahrenheit() << "°F\n";
                break;
            case 4:
                fahrenheit.setTemperature(temperature);
                cout << fahrenheit.getTemperature() << "°F = " << fahrenheit.toCelsius() << "°C\n";
                break;
            case 5:
                kelvin.setTemperature(temperature);
                cout << kelvin.getTemperature() << "K = " << kelvin.toFahrenheit() << "°F\n";
                break;
            case 6:
                fahrenheit.setTemperature(temperature);
                cout << fahrenheit.getTemperature() << "°F = " << fahrenheit.toKelvin() << "K\n";
                break;
            case 7:
                break;
            default:
                cout << "Ingrese una opcion valida\n";
                break;
        }
    }while(opc!=7);
    system("pause");
    system("cls");
    return 0;
}
