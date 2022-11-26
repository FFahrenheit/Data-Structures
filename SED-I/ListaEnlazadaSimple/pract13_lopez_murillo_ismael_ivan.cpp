#include <iostream>
#include <cstdlib>
#include <string.h>
#include <algorithm>

using namespace std;

/*
    Ismael Ivan Lopez Murillo
    Compilar con C++>=11
*/

template<typename T>
class Nodo
{
    public:
        Nodo();
        Nodo(T,T);
        ~Nodo();
        Nodo *next;
        T id;
        T nombre;
        void print();
};

template<typename T>
Nodo<T>::Nodo()
{   id= NULL;
    nombre=NULL;
    next=NULL;
}

template<typename T>
Nodo<T>::Nodo(T id_,T nombre_ )
{
    id=id_;
    nombre=nombre_;
    next=NULL;
}

template<typename T>
void Nodo<T>::print()
{
    cout<<"Id: " << id << endl;
    cout<<"Nombre: " << nombre << endl;
}

template<typename T>
Nodo<T>::~Nodo()
{
}

template<class T>
class List
{
    private:
        Nodo<T> *ptrHead;
        int number_nodo;
        int getMax();
        Nodo<T> getAt(int);
    public:
        List();
        ~List();

        void add_head(T,T);
        void add_end(T,T);
        void add_sort(T,T);
        void delete_position(int);
        void delete_position(int,int);
        void print();
        void Search(T);
        void buscar_pos(int);
        void invertir();
        void buscar_nom(T);
        void Eliminar_Todo();
        void Ordenar();
        void Modificar(int);
};

template <typename T>
Nodo<T> List<T>::getAt(int position)
{
    Nodo<T> * aux = ptrHead;
    for(int i=1; i<position;i++)
    {
        aux = aux->next;
    }
    return *aux;
}

template <typename T>
int List<T>::getMax()
{
    int maxIndex = 1;
    T maxValue = ptrHead->nombre;
    Nodo<T> * aux = ptrHead->next;
    int count = 2;
    while(aux!=NULL)
    {
        if(is_same<T, string>::value)
        {
            string comp = (string) aux->nombre;
            if(comp.compare((string)maxValue)>0)
            {
                maxIndex = count;
                maxValue = aux->nombre;
            }
        }
        else
        {
            if(aux->nombre > maxValue)
            {
                maxIndex = count;
                maxValue = aux->nombre;
            }
        }
        aux = aux->next;
        ++count;
    }
    return maxIndex;
}

template <typename T>
void List<T>::Ordenar()
{
    int tempCounter = number_nodo;
    Nodo<T> * auxHead = NULL;
    Nodo<T> * auxAux;
    while(number_nodo > 0)
    {
        int deletedPosition = getMax();
        Nodo<T> temp = getAt(deletedPosition);
        auxAux = new Nodo<T>(temp.id,temp.nombre);
        if(!auxHead){
            auxHead=auxAux;
        }
        else{
            auxAux->next=auxHead;
            auxHead= auxAux;
        }
        delete_position(deletedPosition,0);
    }
    ptrHead = auxHead;
    number_nodo = tempCounter;
}

template <typename T>
void List<T>::buscar_nom(T nombre)
{
    bool found = false;
    int count = 1;
    Nodo<T> * aux = ptrHead;
    while(aux!=NULL)
    {
        if(aux->nombre == nombre)
        {
            cout << "\nEncontrado en la posicion " << count << endl;
            aux->print();
            found = true;
        }
        count++;
        aux = aux->next;
    }
    if(!found)
    {
        cout << "El nombre no se encuentra en la lista" << endl;
    }
}

template <typename T>
void List<T>::invertir()
{
    Nodo<T> * current  = ptrHead;
    Nodo<T> *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    ptrHead = prev;
}

template <typename T>
void List<T>::delete_position(int position,int x)
{
        if(position == 1)
        {
            Nodo<T> * aux = ptrHead;
            ptrHead = ptrHead->next;
            delete aux;
        }
        else
        {
            Nodo<T> * aux = ptrHead;
            for(int i=1; i<position-1;i++)
            {
                aux = aux->next;
            }
            Nodo<T> * aux2 = aux->next;
            aux->next = aux->next->next;
            delete(aux2);
        }
        --number_nodo;
}


template <typename T>
void List<T>::delete_position(int position)
{
    if(number_nodo==0)
    {
        cout << "La lista esta vacia" << endl;
    }
    else if(position<=0)
    {
        cout << "El indice no es valido" << endl;
    }
    else if(position > number_nodo)
    {
        cout << "El indice esta fuera del rango" << endl;
    }
    else
    {
        if(position == 1)
        {
            Nodo<T> * aux = ptrHead;
            ptrHead = ptrHead->next;
            delete aux;
        }
        else
        {
            Nodo<T> * aux = ptrHead;
            for(int i=1; i<position-1;i++)
            {
                aux = aux->next;
            }
            Nodo<T> * aux2 = aux->next;
            aux->next = aux->next->next;
            delete(aux2);
        }
        --number_nodo;
        cout << "Elemento eliminado" << endl;
    }
}

template<typename T>
List<T>::List()
{
    number_nodo=0;
    ptrHead=NULL;
}

template<typename T>
void List<T>::Eliminar_Todo()
{
    Nodo<T> * aux = ptrHead;
    while(ptrHead != nullptr)
    {
        aux = ptrHead->next;
        delete(ptrHead);
        ptrHead = aux;
    }
    number_nodo = 0;
}

template<typename T>
List<T>::~List()
{
    Nodo<T> * aux = ptrHead;
    while(ptrHead != nullptr)
    {
        aux = ptrHead->next;
        delete(ptrHead);
        ptrHead = aux;
    }
}

//Insertar al inicio
template<typename T>
void List<T>::add_head(T id_,T nombre_)
{
    Nodo<T> *new_nodo=new Nodo<T>(id_,nombre_);
    Nodo<T> *temp = ptrHead;
    if(!ptrHead){
        ptrHead=new_nodo;
    }
    else{
        new_nodo->next=ptrHead;
        ptrHead= new_nodo;
        while(temp){
            temp=temp->next;
        }
    }
    number_nodo++;
}

template <typename T>
void List<T>::add_sort(T id_,T nombre_)
{
    Nodo<T> *new_nodo= new Nodo<T> (id_,nombre_);
    Nodo<T> *temp=ptrHead;
    if (!ptrHead){
        ptrHead=new_nodo;
    }
    else{
            if(ptrHead->id==id_){
                new_nodo->next=ptrHead;
                ptrHead=new_nodo;
            }
            else{
                while(temp->next!=NULL){
                    temp= temp->next;
                }
                new_nodo->next=temp->next;
                temp->next=new_nodo;
            }
    }
    number_nodo++;
}


template<typename T>
void List<T>::print()
{
 Nodo<T> *temp=ptrHead;
    if(!ptrHead)
    {
        cout<<"La Agenda esta vacia\n";
    }
    else
    {
        while(temp)
        {
            temp->print();
            cout<<"\n";
            temp=temp->next;
        }
    }
}

template<typename T>
void List<T>::Search(T id_)
{
    Nodo<T> *temp=ptrHead;
    int count1=1,count2=0;
    while(temp){
        if(temp->id==id_){
            cout<<"Encontrado en la posicion:"<<count1<<endl;
            count2++;
        }
        temp=temp->next;
        count1++;
    }
    if(count2==0){
        cout<<"No existe el dato\n";
    }
    cout<<"\n\n";
}

template<typename T>
void List<T>::buscar_pos(int pos)
{
    Nodo<T> *aux=ptrHead;
    if(number_nodo==0)
        cout<<"Agenda esta vacia\n";
    else{
    if(pos<number_nodo+1&&pos>0){
        for(int i=1;i<pos;i++){
            cout<<"aux"<<i<<"="<<aux->id<<endl;
                aux=aux->next;
        }
    cout<<"Id-."<<aux->id<<endl;
    cout<<"Nombre-."<<aux->nombre<<endl;

        }
        else
        cout<<"Posicion invalida\n";
    }
}

template<typename T>
void List<T>::Modificar(int pos)
{
    if(ptrHead==NULL)
    {
        cout<<"La agenda esta vacia\n";
    }
    else
    {
        if(pos>number_nodo)
        {
            cout<<"posicion invalida\n";
        }
        else if(pos<0)
        {
            cout<<"posicion invalida\n";
        }
        else
        {
            char opc;
            string cad;
            Nodo<T>* aux1=ptrHead;
            for(int i=1;i<pos;i++){
                aux1=aux1->next;
            }
            do
            {
                cout<<"1-.Cambiar ID\n";
                cout<<"2-.Cambiar Nombre\n";
                cout<<"0-.Salir\n";

                cin.sync();
                cin>>opc;

                switch(opc)
                {
                    case '1':
                    {
                        getline(cin,cad);
                        cout<<"Ingresa el nuevo Id: ";
                        getline(cin,cad);
                        aux1->id=cad;
                        break;
                    }
                    case '2':
                    {
                        getline(cin,cad);
                        cout<<"Ingresa el nuevo nombre: ";
                        getline(cin,cad);
                        aux1->nombre=cad;
                        break;
                    }
               }
               system("cls");
            }while(opc!='0');
        }
    }
}

bool isInteger(string);
int toInteger(string);
int requestInt(string);
string requestIntAsString(string);


int main (int argc,char *argv[])
{
    List<string> list1;
    int element,dimention,pos,dat;
    string id_ ,nombre_,correo_,numero_,direccion_;
    int opc;
    do{
        cout<<"1-.Agregar contacto \n";         //Listo
        cout<<"2-.Buscar contacto.\n";          //Listo por ID
        cout<<"3-.Eliminar contacto.\n";        //Listo
        cout<<"4-.Buscar por posicion\n";       //Listo
        cout<<"5-.Invertir\n";                  //Listo
        cout<<"6-.Buscar por nombre\n";         //Listo
        cout<<"7-.Ordenar alfabeticamente\n";   //Listo
        cout<<"8-.Imprimir datos\n";            //Listo
        cout<<"9-.Modificar\n";                 //Listo
        cout<<"10-.Eliminar Todo\n";            //TAREA
        cout<<"0-.Salir..\n";                   //Listo

        opc = requestInt("Ingrese una opcion: ");
        system("cls");
         switch (opc){
             case 1:{
             	system ("cls");
             	id_ = requestIntAsString("Ingrese el Id: ");
             	cout << "Ingrese el nombre: ";
             	getline(cin,nombre_);
                list1.add_head(id_,nombre_);
                list1.print();
                break;
             }

             case 2:{
                id_ = requestIntAsString("Ingrese el Id del elemento a buscar: ");
                list1.Search(id_);
                break;
             }
             case 3:{
                pos = requestInt("Ingrese la posicion a eliminar: ");
                list1.delete_position(pos);
                list1.print();
                break;
             }
             case 4:{
                cout<<"Ingresa la posicion que quieres buscar: ";
                cin.sync();
                cin>>element;
                list1.buscar_pos(element);
                break;
             }
             case 5:{
                 cout << "Lista antes\n";
                 list1.print();
                 cout << "Lista despues\n";
                 list1.invertir();
                 list1.print();
                break;
             }
             case 6:{
                 cout << "Ingrese el nombre a buscar: ";
                 getline(cin, nombre_);
                 list1.buscar_nom(nombre_);
                break;
             }
             case 7:{
                 cout << "Lista antes\n";
                    list1.print();
                    cout << "Lista despues\n";
                    list1.Ordenar();
                    list1.print();
                    break;
             }
             case 8:{
                list1.print();
                break;
             }
             case 9:{
                cout<<"Ingresa la posicion del dato a modificar\n";
                cin.sync();
                cin>>dat;
                list1.Modificar(dat);
                break;
             }
             case 0:
                 cout << "Gracias por usar esta lista" << endl;
             case 10:{
                    list1.Eliminar_Todo();
                    cout << "Todo eliminado" << endl;
                    break;
              }

        }
        cout<<endl;
        system("pause");
        system("cls");
    }while(opc!=0);
    return 0;
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

string requestIntAsString(string const message)
{
    string input;
    do
    {
        cout << message;
        getline(cin,input);
        if(!isInteger(input))
        {
            cout << "Ingrese una entrada valida" << endl;
        }
    }while(!isInteger(input));
    return input;
}

int requestInt(string const message)
{
    return toInteger(requestIntAsString(message));
}


