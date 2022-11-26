//
// Created by ivan_ on 14/04/2021.
//

#ifndef PROGRAMA03_GRAFO_H
#define PROGRAMA03_GRAFO_H

#include "Lista.h"
#include "Vertice.h"
#include "Evento.h"

template <typename T>
class Grafo {
private:
    Lista<Vertice<T>> vertices;    //Un grafo es una lista de vertices
public:
    Grafo(){
        vertices = Lista<Vertice<T>>();
    }

    void mostrar();
    bool agregar_vertice(T);
    void listar();
    bool agregar_arista(T, T, int);
    Lista<Vertice<T>> get_vertices();
    bool eliminar_vertice(T);
    bool eliminar_arista(T,T);
    bool guardar(string filename);

    bool cargar(string basicString);
};

template<typename T>
bool Grafo<T>::agregar_vertice(T dato) {
    if(vertices.find(Vertice<T>(dato))!=-1){
        return false;
    }

    vertices.push_back(Vertice<T>(dato));
    return true;
}

template<typename T>
void Grafo<T>::mostrar() {
    for(size_t i(0);i<vertices.size();i++){
        cout << endl;
        vertices.get(i).mostrar();
    }
}

template<typename T>
void Grafo<T>::listar() {
    for(size_t i(0); i<vertices.size();i++){
        T dato = vertices.get(i).getDato();
        cout << "[ " << dato.getIdSuceso() << " ]"
                << " : " << dato.getDescripcion()
                    << " (" << dato.getFecha() << ")\n";
    }
}

template<typename T>
bool Grafo<T>::agregar_arista(T origen, T destino, int costo) {
    int uPos = vertices.find(origen);
    int vPos = vertices.find(destino);

    if(uPos == -1 || vPos == -1){
        return false;
    }

    return vertices.get(uPos).agregarArista(&vertices.get(vPos),costo);
}

template<typename T>
Lista<Vertice<T>> Grafo<T>::get_vertices() {
    return vertices;
}

template<typename T>
bool Grafo<T>::eliminar_vertice(T u) {
    int pos = vertices.find(u);
    if(pos == -1){
        return false;
    }

    Vertice<T> vertice = vertices.get(pos);

    for(size_t i(0); i<vertices.size(); i++){
        vertices.get(i).borrarCoincidencias(&vertice);
    }

    vertices.erase(pos);
    return true;
}

template<typename T>
bool Grafo<T>::eliminar_arista(T origen, T destino) {
    int uPos = vertices.find(origen);
    int vPos = vertices.find(destino);

    if(uPos == -1 || vPos == -1){
        return false;
    }

    return vertices.get(uPos).eliminarArista(&vertices.get(vPos));}

template<typename T>
bool Grafo<T>::guardar(string filename) {
    fstream file;
    file.open(filename,ios::out);

    if(file.is_open()){
        file << vertices.size() << endl;
        for(size_t i=0; i<vertices.size();i++){
            file << vertices.get(i).getDato();
        }

        file << "\n";

        for(size_t i=0; i<vertices.size();i++){
            file << vertices.get(i).aristasLista();
        }
        file.close();
        return true;
    }
    return false;

}

template<typename T>
bool Grafo<T>::cargar(string filename) {
    fstream file;
    file.open(filename,ios::in);

    if(file.is_open()){
        int size;
        string aux;
        T dato;

        getline(file,aux,'\n');

        size = stoi(aux);

        for(size_t i(0);i<size;i++){
            file >> dato;
            vertices.push_back(Vertice<T>(dato));
        }

        getline(file,aux,'\n');

        while(true){
            getline(file,aux,'|');

            if(aux.empty()){
                break;
            }else{
                int origen,destino,peso;

                origen = stoi(aux);

                getline(file,aux,'|');
                destino = stoi(aux);

                getline(file,aux,'*');
                peso = stoi(aux);

                agregar_arista(
                        Evento(origen),
                        Evento(destino),
                        peso);
            }
        }
        file.close();
        return true;
    }
    return false;
}

#endif //PROGRAMA03_GRAFO_H
