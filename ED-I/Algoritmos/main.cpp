#include <iostream>
#include "ListaEstatica.h"
#include "algoritmos.h"
#include <time.h>

/***
 * Tgo. Ismael Ivan Lopez Murillo
***/

using namespace std;

int main()
{
    srand (time(NULL));
    ListaEstatica<int> numeros;
    for(size_t i(0); i<8;i++)
    {
        size_t size = rand()%200+10;
        size_t toSearch = rand()%(size-1);
        int query;
        numeros.clear();
        for(size_t j(0); j<size;j++)
        {
            int generated = rand()%100+1;
            if(j == toSearch)
            {
                query = generated;
            }
            numeros.push_back(generated);
        }
        numeros.print();
        switch(i)
        {
            case 0:
                cout << "BubbleSort";
                bubbleSort(numeros);
                break;
            case 1:
                cout << "InsertionSort";
                insertionSort(numeros);
                break;
            case 2:
                cout << "ShellSort";
                shellSort(numeros);
                break;
            case 3:
                cout << "SelecionSort";
                selectionSort(numeros);
                break;
            case 4:
                cout << "QuickSort";
                quickSort(numeros);
                break;
            case 5:
                cout << "MergeSort";
                mergeSort(numeros);
                break;
            case 6:
                cout << "Busqueda secuencial";
                break;
            case 7:
                cout << "Busqueda binaria";
                quickSort(numeros); //Necesitamos ordenarlos
                break;
        }
        numeros.print();
        if(i == 6 || i == 7)
        {
            cout << "Se busca: " << query<<endl;
            if(i==6)
            {
                cout << "Se encontro en: " <<  sequentialSearch(numeros,query)<<endl;
                cout << "Este elemento (1400) no se va a encontrar, entonces => "
                        << sequentialSearch(numeros,1400)<<endl;
            }
            else
            {
                cout << "Se encontro en: " <<  binarySearch(numeros,query)<<endl;
                cout << "Este elemento (1500) no se va a encontrar, entonces => "
                        << binarySearch(numeros,1500)<<endl;
            }
        }
    }
    return 0;

}
