//
// Created by ivan_ on 25/03/2021.
//

#include <windows.h>

bool AjustarVentana(int Ancho, int Alto)
{
    _COORD Coordenada;
    Coordenada.X = Ancho;
    Coordenada.Y = Alto;
    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Right = Ancho - 1;
    Rect.Bottom = Alto - 1;
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(hConsola, Coordenada);
    SetConsoleWindowInfo(hConsola, TRUE, &Rect);
    return true;
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