#include <iostream>
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Rectangulo.h"

using namespace std;

int main()
{
    double base, altura;
    Triangulo triangulo;
    Cuadrado cuadrado;
    Rectangulo rectangulo;
    int opc;
    do
    {
        cout << endl << "\t\t\tMENU" << endl<<endl;
        cout << "1) Triangulo" << endl;
        cout << "2) Cuadrado" << endl;
        cout << "3) Rectangulo" << endl;
        cout << "4) Salir" << endl;
        cout << "Su opcion: ";
        cin >> opc;
        switch(opc)
        {
            case 1:
                {
                    cout << "\n\tTriangulo"<<endl;
                    cout << "Ingrese base: ";
                    cin >> base;
                    triangulo.setBase(base);
                    cout << "Ingrese altura: ";
                    cin >> altura;
                    triangulo.setAltura(altura);
                    triangulo.calcularArea();
                    cout << "El area del triangulo es " << triangulo.getArea() << endl;
                    break;
                }
            case 2:
                {
                    cout << "\n\tCuadrado"<<endl;
                    cout << "Ingrese base: ";
                    cin >> base;
                    cuadrado.setBase(base);
                    cout << "Ingrese altura: ";
                    cin >> altura;
                    cuadrado.setAltura(altura);
                    cuadrado.calcularArea();
                    cout << "El area del cuadrado es " << cuadrado.getArea() << endl;
                    break;
                }
            case 3:
                {
                    cout << "\n\tRectangulo"<<endl;
                    cout << "Ingrese base: ";
                    cin >> base;
                    rectangulo.setBase(base);
                    cout << "Ingrese altura: ";
                    cin >> altura;
                    rectangulo.setAltura(altura);
                    rectangulo.calcularArea();
                    cout << "El area del rectangulo es " << rectangulo.getArea() << endl;
                    break;
                }
            case 4:
                {
                    break;
                }
            default:
                {
                    cout << "Ingrese una opcion valida" << endl;
                    break;
                }
        }
    }while(opc!=4);
    system("pause");
    system("cls");
}
