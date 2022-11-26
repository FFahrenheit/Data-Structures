#include <iostream>
#include "Mascota.h"

using namespace std;

void mostrarMascota(Mascota&);

int main()
{
    string nombre, tipo;
    int edad;
    //Declarando a mi mascota Chop
    Mascota chop;
    chop.setNombre("Chop");
    chop.setTipo("perrito");
    chop.setEdad(1);

    //Alimentando a Chop con zanahoria (le gustan :3)
    cout << "Te presento a mi mascota:\n";
    mostrarMascota(chop);
    chop.comer("zanahoria");
    system("pause");

    //Es momento de que me presentes a tu mascota
    Mascota otraMascota;
    cout << "Que mascota tienes?" << endl;
    getline(cin, tipo);
    otraMascota.setTipo(tipo);
    string esp = tipo.back() == 'a' ? "Una " : "Un ";
    cout << esp << otraMascota.getTipo() << "...\nQue bonito! Como se llama?" << endl;
    getline(cin,nombre);
    otraMascota.setNombre(nombre);
    cout << "Y que edad tiene " << otraMascota.getNombre() << "?" <<endl;
    cin >> edad;
    otraMascota.setEdad(edad);
    cout << "Perfecto! Le tengo algo a " << otraMascota.getNombre() << endl;
    mostrarMascota(otraMascota);

    //Lo alimentaré
    otraMascota.comer("alimento totalmente apropiado");

    system("pause");
    return 0;
}

void mostrarMascota(Mascota &mascota)
{
    cout << "Resumen de mascota\n";
    cout << "Nombre: " << mascota.getNombre() << endl;
    cout << "Tipo: " << mascota.getTipo() << endl;
    cout << "Edad: " << mascota.getEdad() << " primavera(s)"<<endl;
}