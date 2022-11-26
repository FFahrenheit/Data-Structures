#include <iostream>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include <time.h>
#include "Cola.h"
#include "Pasajero.h"
#include "Pila.h"

/***
 Ismael Ivan Lopez Murillo
 Compile using C++>=11
***/

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


using namespace std;

const int ROWS = 120;
const int COLS = 30;

void setupConsole();
void drawFrame();
void gotoxy(int,int);
int printTitle();
void changeColor(int);
bool isInteger(string);
int toInteger(string);
int requestInt(string);
void despegue();
void avion();
void endScreen();

int pasajeros;
Cola<Pasajero> colaBoletos, colaMaletas,colaTaxis;
Pila<Pasajero> pilaAbordaje;


int main()
{
    colaBoletos = Cola<Pasajero>();
    colaMaletas = Cola<Pasajero>();
    pilaAbordaje = Pila<Pasajero>();
    colaTaxis = Cola<Pasajero>();

    setupConsole();
    pasajeros = printTitle();
    system("cls");

    srand (time(NULL));

    changeColor(WHITE);
    for(int i=0;i<120;i++)
    {
        cout << "*";
    }
    for(int i=0; i<pasajeros;i++)
    {
        gotoxy(0,0);
        cout << "\t\t\t\t\t\tREGISTRO DE PASAJEROS\n";
        Pasajero p = Pasajero(i);
        colaBoletos.push(p);
    }

    system("cls");

    for(int i=0; i<pasajeros;i++)
    {
        gotoxy(0,0);
        cout << "\t\t\t\t\t\tREVISION DE MALETAS\n";
        Pasajero p = colaBoletos.getInicio();
        colaBoletos.pop();
        p.checarEquipaje(rand()%5+1,i);
        colaMaletas.push(p);
        pilaAbordaje.push(p);
    }

    despegue();

    system("cls");
    for(int i=0; i<pasajeros;i++)
    {
        gotoxy(0,0);
        cout << "\t\t\t\t\t\tLLEGADA AL AUROPUERTO\n";
        Pasajero p = pilaAbordaje.getTope();
        pilaAbordaje.pop();
        p.bajarAvion(i);
        colaTaxis.push(p);
    }

    system("cls");
    for(int i=0; i<pasajeros;i++)
    {
        gotoxy(0,0);
        cout << "\t\t\t\t\t\tTOMA DE TAXIS\n";
        Pasajero p = colaTaxis.getInicio();
        colaTaxis.pop();
        p.tomarTaxi(i);
    }

    endScreen();

    return 0;
}

void endScreen()
{
    system("cls");
    drawFrame();
    gotoxy(0,10);
    cout<<"\t\t\t           .--.    _..._    \n";
    cout<<"\t\t\t     _.._  |__|  .'     '.  \n";
    cout<<"\t\t\t   .' .._| .--. .   .-.   . \n";
    cout<<"\t\t\t   | '     |  | |  '   '  | \n";
    cout<<"\t\t\t __| |__   |  | |  |   |  | \n";
    cout<<"\t\t\t|__   __|  |  | |  |   |  | \n";
    cout<<"\t\t\t   | |     |  | |  |   |  | \n";
    cout<<"\t\t\t   | |     |__| |  |   |  | \n";
    cout<<"\t\t\t   | |          |  |   |  | \n";
    cout<<"\t\t\t   | |          |  |   |  | \n";
    cout<<"\t\t\t   |_|          '--'   '--' \n";

    cout << "\n\n\t| _,_    _ |  |    ,_  |      _ _   |\\/|    .||  \n";
    cout << "\t|_\\|||(|(/_|  |\\/(|||  |_()|)(/_/_  |  |L||`|||()\n";
    cout << "\t                           |                    \n";

    gotoxy(60,10);

    cout << "Presione una tecla para terminar el proyecto";
    getch();
    gotoxy(1,0);
    exit(0);
}

void despegue()
{
    system("cls");
    drawFrame();
    gotoxy(0,5);
    cout <<"\t\t\t\t\t\t 333333333333333\n";
    cout << "\t\t\t\t\t\t3:::::::::::::::33 \n";
    cout << "\t\t\t\t\t\t3::::::33333::::::3\n";
    cout << "\t\t\t\t\t\t3333333     3:::::3\n";
    cout << "\t\t\t\t\t\t            3:::::3\n";
    cout << "\t\t\t\t\t\t            3:::::3\n";
    cout << "\t\t\t\t\t\t    33333333:::::3 \n";
    cout << "\t\t\t\t\t\t    3:::::::::::3  \n";
    cout << "\t\t\t\t\t\t    33333333:::::3 \n";
    cout << "\t\t\t\t\t\t            3:::::3\n";
    cout << "\t\t\t\t\t\t            3:::::3\n";
    cout << "\t\t\t\t\t\t            3:::::3\n";
    cout << "\t\t\t\t\t\t3333333     3:::::3\n";
    cout << "\t\t\t\t\t\t3::::::33333::::::3\n";
    cout << "\t\t\t\t\t\t3:::::::::::::::33 \n";
    cout << "\t\t\t\t\t\t 333333333333333   \n";
    Sleep(1500);
    gotoxy(0,5);
    cout<<"\t\t\t\t\t\t 222222222222222  \n";
    cout<<"\t\t\t\t\t\t2:::::::::::::::22  \n";
    cout<<"\t\t\t\t\t\t2::::::222222:::::2 \n";
    cout<<"\t\t\t\t\t\t2222222     2:::::2 \n";
    cout<<"\t\t\t\t\t\t            2:::::2 \n";
    cout<<"\t\t\t\t\t\t            2:::::2 \n";
    cout<<"\t\t\t\t\t\t         2222::::2  \n";
    cout<<"\t\t\t\t\t\t    22222::::::22   \n";
    cout<<"\t\t\t\t\t\t  22::::::::222     \n";
    cout<<"\t\t\t\t\t\t 2:::::22222        \n";
    cout<<"\t\t\t\t\t\t2:::::2             \n";
    cout<<"\t\t\t\t\t\t2:::::2             \n";
    cout<<"\t\t\t\t\t\t2:::::2       222222\n";
    cout<<"\t\t\t\t\t\t2::::::2222222:::::2\n";
    cout<<"\t\t\t\t\t\t2::::::::::::::::::2\n";
    cout<<"\t\t\t\t\t\t22222222222222222222\n";
    Sleep(1500);
    gotoxy(0,5);
    cout<<"\t\t\t\t\t\t  1111111            \n";
    cout<<"\t\t\t\t\t\t 1::::::1               \n";
    cout<<"\t\t\t\t\t\t1:::::::1               \n";
    cout<<"\t\t\t\t\t\t111:::::1               \n";
    cout<<"\t\t\t\t\t\t   1::::1               \n";
    cout<<"\t\t\t\t\t\t   1::::1               \n";
    cout<<"\t\t\t\t\t\t   1::::1               \n";
    cout<<"\t\t\t\t\t\t   1::::l               \n";
    cout<<"\t\t\t\t\t\t   1::::l               \n";
    cout<<"\t\t\t\t\t\t   1::::l               \n";
    cout<<"\t\t\t\t\t\t   1::::l               \n";
    cout<<"\t\t\t\t\t\t   1::::l               \n";
    cout<<"\t\t\t\t\t\t111::::::111            \n";
    cout<<"\t\t\t\t\t\t1::::::::::1            \n";
    cout<<"\t\t\t\t\t\t1::::::::::1            \n";
    cout<<"\t\t\t\t\t\t111111111111            \n";
    Sleep(2000);
    system("cls");
    drawFrame();
    avion();
}

void avion()
{
    system("cls");
    drawFrame();
    changeColor(CYAN);
    gotoxy(0,10);
    cout << "\t\t\t\t__  _\n";
    cout << "\t\t\t\t\\ `/ |\n";
    cout << "\t\t\t\t\\__`!\n";
    cout << "\t\t\t\t / ,' `-.__________________\n";
    cout << "\t\t\t\t'-'\\_____                LI`-.\n";
    cout << "\t\t\t\t   <____()-=O=O=O=O=O=[]====--)\n";
    cout << "\t\t\t\t     `.___ ,-----,_______...-'\n";
    cout << "\t\t\t\t          /    .'\n";
    cout << "\t\t\t\t         /   .'\n";
    cout << "\t\t\t\t        /  .'        \n";
    cout << "\t\t\t\t        `-'\n";
    changeColor(WHITE);
    for(int i=0; i<55;i++)
    {
        gotoxy(10+i,3);cout << "           .-~~~-.\n";
        gotoxy(10+i,4);cout << "   .- ~ ~-(       )_ _n";
        gotoxy(10+i,5);cout << "  /                     ~ -.n";
        gotoxy(10+i,6);cout << " |                           \n";
        gotoxy(10+i,7);cout << "  \                         .'n";
        gotoxy(10+i,8);cout << "    ~- . _____________ . -~\n";
        gotoxy(0,21);
        gotoxy(30+i,22);cout << "           .-~~~-.\n";
        gotoxy(30+i,23);cout << "   .- ~ ~-(       )_ _n";
        gotoxy(30+i,24);cout << "  /                     ~ -.n";
        gotoxy(30+i,25);cout << " |                           \n";
        gotoxy(30+i,26);cout << "  \                         .'n";
        gotoxy(30+i,27);cout << "    ~- . _____________ . -~\n";
        Sleep(135);
    }

    gotoxy(80,15);
    cout << "Se ha llegado al destino";
    gotoxy(78,17);
    cout << "Presione una tecla para continuar";
    getch();
}

void changeColor(int val)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), val);
}

int printTitle()
{
    cout << "\n\n\t      .o.                                                                                  .             \n";
    cout << "\t     .888.                                                                               .o8             \n";
    cout << "\t    .8\"888.      .ooooo.  oooo d8b  .ooooo.  oo.ooooo.  oooo  oooo   .ooooo.  oooo d8b .o888oo  .ooooo.  \n";
    cout << "\t   .8' `888.    d88' `88b `888\"\"8P d88' `88b  888' `88b `888  `888  d88' `88b `888\"\"8P   888   d88' `88b \n";
    cout << "\t  .88ooo8888.   888ooo888  888     888   888  888   888  888   888  888ooo888  888       888   888   888 \n";
    cout << "\t .8'     `888.  888    .o  888     888   888  888   888  888   888  888    .o  888       888 . 888   888 \n";
    cout << "\to88o     o8888o `Y8bod8P' d888b    `Y8bod8P'  888bod8P'  `V88V\"V8P' `Y8bod8P' d888b      \"888\" `Y8bod8P' \n";
    cout << "\t                                              888                                                        \n";
    cout << "\t                                             o888o                                                       \n\n\n";
    changeColor(CYAN);
    cout << "\t\t__  _\n";
    cout << "\t\t\\ `/ |\n";
    cout << " \t\t\\__`!\n";
    cout << "\t\t / ,' `-.__________________\n";
    cout << "\t\t'-'\\_____                LI`-.\n";
    cout << "\t\t   <____()-=O=O=O=O=O=[]====--)\n";
    cout << "\t\t     `.___ ,-----,_______...-'\n";
    cout << "\t\t          /    .'\n";
    cout << "\t\t         /   .'\n";
    cout << "\t\t        /  .'        \n";
    cout << "\t\t        `-'\n";
    changeColor(WHITE);
    cout << "\n\n\t| _,_    _ |  |    ,_  |      _ _   |\\/|    .||  \n";
    cout << "\t|_\\|||(|(/_|  |\\/(|||  |_()|)(/_/_  |  |L||`|||()\n";
    cout << "\t                           |                    \n";

    gotoxy(60,15);
    cout << "Presione una tecla para empezar el vuelo...";
    drawFrame();
    gotoxy(60,16);
    getch();
    gotoxy(60,17);
    cout << "Ingrese el numero de pasajeros (capacidad maxima: 20)";
    gotoxy(60,18);
    cout << "Pasajeros: ";
    return requestInt("");
}

void drawFrame()
{
    changeColor(LIGHTBLUE);
    gotoxy(0,0);cout << (char) 201;
    gotoxy(ROWS-1,0);cout << (char)187;
    gotoxy(0,COLS-1);cout<< (char) 200;
    gotoxy(ROWS-1,COLS-1);cout<< (char)188;
    for(int i=1; i<ROWS-1;i++)
    {
        gotoxy(i,0);
        cout << (char) 205;
        gotoxy(i,COLS-1);
        cout << (char) 205;
    }
    for(int i=1; i<COLS-1;i++)
    {
        gotoxy(0,i);
        cout << (char) 186;
        gotoxy(ROWS-1,i);
        cout << (char) 186;
    }
    gotoxy(20,20);
}

 void gotoxy(int x,int y)
 {
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

void setupConsole()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1000,530, TRUE);
}


 bool isInteger(string s)
{
    if(s.empty())
    {
        return false;
    }
    if(s.at(0)=='-')
    {
        return !s.empty() && all_of(s.begin()+1, s.end(), ::isdigit); //Todo sea digito
    }
    else
    {
        return !s.empty() && all_of(s.begin()+1, s.end(), ::isdigit);
    }
}

int toInteger(string const number)
{
    return std::stoi(number);
}

 int requestInt(string const message)
{
    string input;
    do
    {
        gotoxy(71,18);
        cout << "          ";
        gotoxy(71,18);
        getline(cin,input);
    }while(!isInteger(input) || toInteger(input)<1 || toInteger(input)>20);
    return toInteger(input);
}

