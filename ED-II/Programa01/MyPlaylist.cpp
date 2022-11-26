//
// Created by ivan_ on 10/03/2021.
//

#include "MyPlaylist.h"

MyPlaylist::MyPlaylist() {
    this->list = LSL<Song>();
}

void MyPlaylist::menu() {
    char opc;
    cout << "Desea importar la playlist desde el archivo? Y / N: ";
    cin >> opc;
    if(opc=='Y' || opc == 'y'){
        this->list.load("file01.txt");
    }
    do{
        system("cls");
        size_t index;
        cout << "\n\t\tMENU PARA PLAYLIST\n\n";
        cout << "1) Agregar cancion al final" << endl;
        cout << "2) Agregar cancion en posicion" << endl;
        cout << "3) Borrar cancion en posicion" << endl;
        cout << "4) Mostrar canciones" << endl;
        cout << "5) Buscar por titulo de cancion" << endl;
        cout << "6) Cargar desde archivo" << endl;
        cout << "7) Guardar mi playlist" << endl;
        cout << "8) Salir" << endl;
        cout << "Su eleccion: ";
        cin >> opc;
        cin.ignore();
        switch(opc){
            case '1':
                addSong(0);
                break;
            case '2':
                cout << "Ingrese la posicion donde guardar. De 1 a " << list.size() + 1 << ": ";
                cin >> index;
                cin.ignore();
                addSong(index-1);
                break;
            case '3':
                if(!list.empty()){
                    cout << "Ingrese la posicion donde borrar. De 1 a " << list.size() << ": ";
                    cin >> index;
                    this->list.erase(index-1);
                    cout << "Cancio borrada" << endl;
                }else{
                    cout << "Ingrese elementos primero" << endl;
                }
                break;
            case '4':
                for(size_t i(0); i< this->list.size(); i++){
                    cout << "******** " << i+1 << " ********" << endl;
                    this->list[i].show();
                }
                break;
            case '5':
                searchSong();
                break;
            case '6':
                this->list.load("file01.txt");
                cout << "Datos cargados" << endl;
                break;
            case '7':
                this->list.save("file01.txt");
                cout << "Datos guardados" << endl;
                break;
            case '8':
                this->list.save("file01.txt");
                break;
                cout << "Adios" << endl;
        }
        system("pause");
    }while(opc != '8');
}

void MyPlaylist::addSong(size_t index) {
    Song song = Song();
    string aux;
    cout << "Ingrese nombre: ";
    getline(cin,aux);
    song.setName(aux);
    cout << "Ingrese artista: ";
    getline(cin,aux);
    song.setArtist(aux);
    cout << "Ingrese album: ";
    getline(cin,aux);
    song.setAlbum(aux);

    if(index==0){
        this->list.push_back(song);
    }else{
        this->list.insert(index,song);
    }

    cout << "Cancion agregada" << endl;
}

void MyPlaylist::searchSong() {
    Song song = Song();
    string aux;
    cout << "Ingrese el titulo de la cancion a buscar: ";
    getline(cin,aux);
    song.setName(aux);
    int index = list.find(song);
    if(index != -1){
        this->list[index].show();
    }else{
        cout << "Elemento no encontrado" << endl;
    }
}

MyPlaylist::~MyPlaylist() {
    this->list.save("file01.txt");
    this->list.clear();
}

