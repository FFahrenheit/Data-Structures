#include "Pasajero.h"
#include <time.h>
#include <windows.h>
#include <conio.h>

#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15


Pasajero::Pasajero()
{

}

void Pasajero::tomarTaxi(int index)
{
    imprimirInfo();
    gotoxy(100,14);cout<<"  ______";
    gotoxy(100,15);cout<<" /|_||_\`.__";
    gotoxy(100,16);cout<<"(   _    _ _\\";
    gotoxy(100,17);cout<<"=`-(_)--(_)-'";
    for(int i=0; i<(index) ;i++)
    {
        gotoxy(100 - (i+1)*5,15);cout<<" O ";
        gotoxy(100 - (i+1)*5,16);cout<<"/|\\";
        gotoxy(100 - (i+1)*5,17);cout<<"/ \\";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);

    for(int i=0; i<(100 - (index+1)*5); i++)
    {
        gotoxy(i,15);cout<<"  o ";
        gotoxy(i,16);cout<<" /|\\";
        if(i == (100 - (index+1)*5) - 1)
        {
            gotoxy(i,17);cout << " / \\";
        }
        else if(i%2==0)
        {
            gotoxy(i,17);cout<<"  /";
        }
        else
        {
            gotoxy(i,17);cout<<"  \\";
        }
        Sleep(30);
    }
    gotoxy(50,20);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

    cout << "Presione una tecla para continuar";
    getch();
}

void Pasajero::bajarAvion(int index)
{
    imprimirInfo();
    gotoxy(0,13);
    cout<<"        __|__\n";
    cout<<" --------(_)--------\n";
    cout<<"   O  O       O  O\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    for(int i=0; i<(index) ;i++)
    {
        gotoxy(120 - (i+1)*5,13);cout<<" O ";
        gotoxy(120 - (i+1)*5,14);cout<<"/|\\";
        gotoxy(120 - (i+1)*5,15);cout<<"/ \\";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTBLUE);

    for(int i=30; i< 120 - (index+1)*5;i++)
    {
        gotoxy(i,13);cout<<"  o ";
        gotoxy(i,14);cout<<" "<< ""<<"/|\\";
        if(i == 120 - (index+1)*5 - 1)
        {
            gotoxy(i,15);
            cout << " "<<""<<"/ \\";
        }
        else if(i%2==0)
        {
            gotoxy(i,15);cout<<" "<<""<<" /";
        }
        else
        {
            gotoxy(i,15);cout<<" "<<""<<" \\";
        }
        Sleep(35);
    }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

    gotoxy(0,20);
    cout << "\t\t\t\t\tPresione una tecla para continuar...\n";
    getch();
    gotoxy(30,20);
    cout << "                                                             ";

}

 void Pasajero::gotoxy(int x,int y)
 {
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

 void Pasajero::imprimirInfo()
 {
    for(int i=0; i<120;i++)
    {
        cout << "*";
    }

    cout << "\t\t->Nombre pasajero: " << nombre << "                  "<<endl;
    cout << "\t->Destino: " << destino<< "                            "<<endl;
    cout << "\t->Fecha de salida: " << fecha <<"                      "<< endl;
    cout << "\t->Boleto generado: " << boleto <<"                     "<< endl;
    cout << "\t->Id generado: " << id << endl;
    for(int i=0; i<120;i++)
    {
        cout << "*";
    }
 }

void Pasajero::checarEquipaje(int maletas,int index)
{
    imprimirInfo();
    gotoxy(10,10);
    cout << "Maletas del pasajero: " << maletas;
    gotoxy(100,13);cout<<" _   |~  _";
    gotoxy(100,14);cout<<"[_]--'--[_]";
    gotoxy(100,15);cout<<"|'|\"\"`\"\"|'|";
    gotoxy(100,16);cout<<"| | /^\\ | |";
    gotoxy(100,17);cout<<"|_|_|I|_|_|";

    for(int i=0; i<(100 - (index+1)*6); i++)
    {
        gotoxy(i,15);cout<<"    o ";
        gotoxy(i,16);cout<<"  "<<(char)218<<"/|\\";
        if(i == (100 - (index+1)*6) - 1)
        {
            gotoxy(i+1,17);
            cout << " "<<(char)219<<"/ \\";
        }
        else if(i%2==0)
        {
            gotoxy(i,17);cout<<"  "<<(char) 219<<" /";
        }
        else
        {
            gotoxy(i,17);cout<<"  "<<(char)219<<" \\";
        }
        Sleep(30);
    }
    for(int i=0; i<maletas;i++)
    {
        gotoxy(30,20);
        cout << "                                               ";
        gotoxy(30,20);
        cout << "Revisando maleta #" << i+1;
        for(int i=0; i<5;i++)
        {
            cout << ".";
            Sleep(250);
        }
    }
    gotoxy(30,20);
    cout << "Maletas revisadas               ";
    gotoxy(25,23);
    cout << "Presione una tecla para continuar";
    getch();
    gotoxy(30,20);
    cout << "                                               ";
    gotoxy(25,23);
    cout << "                                               ";

}

Pasajero::Pasajero(int index)
{
    srand (time(NULL));
    for(int i=0; i<120;i++)
    {
        cout << "*";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTBLUE);
    gotoxy(0,2);
    cout << "\t->Ingrese nombre:                                        \n";
    cout << "\t->Ingrese destino:                                         \n";
    cout << "\t->Fecha de salida                                           \n";
    cout << "\t->Boleto generado                                           \n";
    cout << "\t->Id generado                                               \n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    for(int i=0; i<120;i++)
    {
        cout << "*";
    }
    gotoxy(0,2);
    cout << "\t->Ingrese nombre: ";
    getline(cin,nombre);
    cout << "\t->Ingrese destino: ";
    getline(cin,destino);
    fecha = "04/11/2020";
    boleto = rand()%1000+1000;
    id = rand()%1000+1;
    cout << "\t->Fecha de salida: " << fecha << endl;
    cout << "\t->Boleto generado: " << boleto << endl;
    cout << "\t->Id generado: " << id << endl;
    gotoxy(100,13);cout<<" _   |~  _";
    gotoxy(100,14);cout<<"[_]--'--[_]";
    gotoxy(100,15);cout<<"|'|\"\"`\"\"|'|";
    gotoxy(100,16);cout<<"| | /^\\ | |";
    gotoxy(100,17);cout<<"|_|_|I|_|_|";
    for(int i=0; i<(index) ;i++)
    {
        gotoxy(100 - (i+1)*5,15);cout<<" O ";
        gotoxy(100 - (i+1)*5,16);cout<<"/|\\";
        gotoxy(100 - (i+1)*5,17);cout<<"/ \\";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);

    for(int i=0; i<(100 - (index+1)*5); i++)
    {
        gotoxy(i,15);cout<<"  o ";
        gotoxy(i,16);cout<<" /|\\";
        if(i == (100 - (index+1)*5) - 1)
        {
            gotoxy(i,17);cout << " / \\";
        }
        else if(i%2==0)
        {
            gotoxy(i,17);cout<<"  /";
        }
        else
        {
            gotoxy(i,17);cout<<"  \\";
        }
        Sleep(30);
    }
    gotoxy(50,20);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

    cout << "Presione una tecla para continuar";
    getch();
    gotoxy(30,20);
    cout << "                                                        ";
}

Pasajero::~Pasajero()
{
    //dtor
}

void Pasajero:: setNombre(string n)
{
    nombre = n;
}

void Pasajero::setDestino(string d)
{
    destino = d;
}

void Pasajero::setFecha(string f)
{
    fecha = f;
}

void Pasajero::setBoleto(int b)
{
    boleto = b;
}

void Pasajero::setId(int i)
{
    id = i;
}

string Pasajero::getNombre()
{
    return nombre;
}

string Pasajero::getDestino()
{
    return destino;
}

string Pasajero::getFecha()
{
    return fecha;
}

int Pasajero::getBoleto()
{
    return boleto;
}

int Pasajero::getId()
{
    return id;
}
