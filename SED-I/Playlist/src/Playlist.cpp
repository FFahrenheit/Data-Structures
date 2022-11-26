#include "Playlist.h"

Playlist::Playlist()
{
    asc = true;
    pkCount = 1;
    cursor = 0;
    cont = 0;
    int opc;
    do
    {
        system("cls");
        printMenu();
        if(asc)
        {
            songs.print();
        }
        else
        {
            songs.printInverse();
        }
        printCursor();
        printControls();
        opc = requestInt("");
        switch(opc)
        {
            case 1:
            {
                Song song(pkCount);
                pkCount++;
                cont++;
                songs.Add(song);
                break;
            }
            case 2:
            {
                if(cont == 0 || cursor == cont-1)
                {
                    cursor = 0;
                }
                else
                {
                    cursor++;
                }
                break;
            }
            case 3:
            {
                if(cont == 0)
                {
                    cursor = 0;
                }
                else if(cursor == 0 && cont != 0)
                {
                    cursor = cont-1;
                }
                else
                {
                    cursor--;
                }
                break;
            }
            case 4:
            {
                if(cont > 0)
                {
                    songs.remove(selected);
                    cursor = 0;
                    cont--;
                }
                break;
            }
            case 5:
            {
                cursor = 0;
                asc = true;
                break;
            }
            case 6:
            {
                cursor = 0;
                asc = false;
                break;
            }
            case 7:
            {
                if(cont > 0)
                {
                    int pos = (asc) ? cursor : cont - cursor - 1;
                    Song s = songs.getAt(pos);
                    songs.remove(s);
                    s.modify();
                    songs.Add(s);
                    cursor = 0;
                }
                break;
            }
            case 8:
            {
                if(asc)
                {
                    songs.deleteFirst();
                }
                else
                {
                    songs.deleteLast();
                }
                cursor = 0;
                cont--;
                break;
            }
            case 9:
            {
                if(asc)
                {
                    songs.deleteLast();
                }
                else
                {
                    songs.deleteFirst();
                }
                cont--;
                cursor = 0;
                break;
            }
            case 0:
            {
                system("cls");
                gotoxy(50,15);
                cout << "Cerrando programa...";
                Sleep(1800);
            }
            default:
            {
                break;
            }

        }
    }while( opc != 0);
}

void Playlist::printControls()
{
    if(cont>0)
    {
        int y;
        if(cont > 10)
        {
            y = cont+3;
        }
        else
        {
            y = 13;
        }

        int pos = (asc) ? cursor : cont - cursor - 1;

        selected = songs.getAt(pos);

        gotoxy(2,y);
        cout << "Titulo: " << selected.getTitle();
        gotoxy(42,y);
        cout << "Album: " << selected.getAlbum();
        gotoxy(2,y+1);
        cout << "Artista: " << selected.getArtist();
        gotoxy(42,y+1);
        cout << "Genero: " << selected.getGenre();
    }
    else
    {
        gotoxy(35,13);
        cout << "Agregue canciones";
    }
}

void Playlist::printCursor()
{
    if(cont > 0)
    {
        gotoxy(0,cursor+2);
        cout << "->";
    }
}

Playlist::~Playlist()
{

}

void Playlist::printMenu()
{
    gotoxy(40,0);
    cout << "C++ Media Player (beta)";
    gotoxy(5,1);
    cout << " Id";
    gotoxy(10,1);
    cout << "Cancion";
    gotoxy(45,1);
    cout << "Artista";
    string controls[] = {
        "[1] Nueva cancion",
        "[2] Adelante",
        "[3] Atras",
        "[4] Borrar",
        "[5] Ordenar Ascendente",
        "[6] Ordenar Descendente",
        "[7] Editar registro",
        "[8] Borrar la primer cancion",
        "[9] Borrar la ultima cancion",
        "[0] Salir"
    };

    for(size_t i(0); i<10; i++)
    {
        gotoxy(80,i+2);
        cout << (char) 219 << " " << controls[i];
    }
}

void Playlist::gotoxy(int x,int y)
{
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}

int Playlist::toInteger(string const number)
{
    return std::stoi(number);
}

string Playlist::requestIntAsString(string const message)
{
    string input;
    gotoxy(80,13);
    cout << "              ";
    gotoxy(80,13);
    do
    {
        cout << message;
        getline(cin,input);
        if(!isInteger(input))
        {
            gotoxy(80,13);
            cout << "                ";
            gotoxy(80,13);
        }
    }while(!isInteger(input));
    gotoxy(80,13);
    cout << "             ";
    return input;
}

int Playlist::requestInt(string const message)
{
    return toInteger(requestIntAsString(message));
}

bool Playlist::isInteger(string s)
{
    if(s.empty())
    {
        return false;
    }
    if(s.at(0)=='-' || s.at(0) == '+')
    {
        return !s.empty() && all_of(s.begin()+1, s.end(), ::isdigit); //Todo sea digito
    }
    else
    {
        return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
    }
}
