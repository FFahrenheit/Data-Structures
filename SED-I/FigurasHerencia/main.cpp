#include <iostream>
#include "Validador.h"
#include "Triangulo.h"
#include "Cuadrado.h"
#include "Rectangulo.h"
#include "Poligono.h"

using namespace std;

int main()
{
    Validador val;
    Triangulo t;
    Cuadrado c;
    Rectangulo r;
    Poligono p;
    int opc;
    do
    {
        string input;
        int lados;
        double base, altura;
        system("cls");
        cout << "1) Calculo area triangulo" << endl;
        cout << "2) Calculo area cuadrado" << endl;
        cout << "3) Calculo area rectangulo" << endl;
        cout << "4) Calculo area poligono" << endl;
        cout << "5) Salir" << endl;
        opc = val.requestInt("Seleccione una opcion: ");
        if(opc>=1 && opc<=3)
        {
            base = (double)val.requestFloat("Ingrese la base: ");
            altura = (double)val.requestFloat("Ingrese la altura: ");
        }
        switch(opc)
        {
            case 1:
                t.setBase(base);
                t.setAltura(altura);
                t.calcularArea();
                cout << "El area es " << t.getArea()<<endl;
                break;
            case 2:
                c.setBase(base);
                c.setAltura(altura);
                c.calcularArea();
                cout << "El area es " << c.getArea()<<endl;
                break;
            case 3:
                r.setBase(base);
                r.setAltura(altura);
                r.calcularArea();
                cout << "El area es " << r.getArea()<<endl;
                break;
            case 4:
                lados = val.requestInt("Ingrese la cantidad de lados: ");
                if(lados>= 5 && lados<=10)
                {
                    p.setLados(lados);
                    p.setBase((double)val.requestFloat("Ingrese la medida de los lados: "));
                    p.setAltura((double)val.requestFloat("Ingrese el apotema: "));
                    p.calcularArea();
                    cout << "El area es " << p.getArea()<<endl;
                }
                else
                {
                    cout << "No es posible calcular el area para " << lados << " lados en este momento\n";
                }
                break;
            case 5:
                cout << "Adioos" << endl;
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
        system("pause");
    }while(opc!=5);
    return 0;
}
