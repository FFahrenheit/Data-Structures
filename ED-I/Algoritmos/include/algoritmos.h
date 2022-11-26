#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "ListaEstatica.h"

/***
 * Busqueda binaria, basicamente buscamos el elemento en rangos,
 * si el elemento es mayor, se toma el rango derecho, sino el
 * izquierdo (NECESITA ESTAR ORDENADO)
***/
template<typename T>
int binarySearch(ListaEstatica<T>& lista, T k)
{
    int le = 0;
    int r = lista.size() - 1;
    while(le <= r)
    {
        int m = (le+r)/2;
        if(lista[m] == k)
        {
            return m;
        }
        else if(lista[m] > k)
        {
            r = m - 1;
        }
        else
        {
            le = m + 1;
        }
    }
    return lista.size();
}

/***
 * Busqueda secuencial, ve elemento por elemento hasta encontrarlo
***/
template<typename T>
size_t sequentialSearch(ListaEstatica<T>& lista, T k)
{
    for(size_t i(0); i<lista.size();i++)
    {
        if(lista[i] == k)
        {
            return i;
        }
    }
    return lista.size();
}

/***
 * Un metodo recursivo de dividir y vencer, usando un pivote y sub-listas
 * podemos encontrar una solucion de forma muy rapida.
***/
template<typename T>
void quickSort(ListaEstatica<T>& lista)
{
    quickSort(lista,0,lista.size()-1);
}

template<typename T>
void quickSort(ListaEstatica<T>& lista, int l, int r)
{
    if(l < r)
    {
        int s = partition(lista,l,r);
        quickSort(lista,l,s-1);
        quickSort(lista,s+1,r);
    }
}

template<typename T>
int partition(ListaEstatica<T>& A, int l, int r)
{
    T p = A[l];
    int i = l;
    int j = r; //No va +1 porque en todo caso queriamos acceder a A[size]
    do
    {
        while(i<j && A[i] <= p) //Si p es el mayor entonces i se irá a extremos, por eso debe ir la condición i<j
        {
            ++i;
        }
        while(A[j] > p) //No puede ser = p, porque ahora si p es el menor entonces nunca acabamos  y nos vamos a extremos
        {
             --j;
        }
        swap(A[i],A[j]);
    }while(i < j);
    swap(A[i],A[j]);
    swap(A[l],A[j]);
    return j;
}

/***
 * Un metodo de divide y vencerás, con mucha complejidad en el sentido
 * de que tenemos que usar copias de la lista, así que habrá que hacer un
 * paso más. Consiste en dividir en pequeñas partes nuestra lista y al final
 * "mergearlas" en el orden correcto.
***/
template<typename T>
void mergeSort(ListaEstatica<T>& lista)
{
    size_t n = lista.size();
    if(n>1)
    {
        size_t p = (n-1)/2;
        ListaEstatica<T> B = copy(lista,0,p);
        ListaEstatica<T> C;
        if(n%2==0)
        {
            C = copy(lista,p+1,n-1);
        }
        else
        {
            C = copy(lista,p+1,n-1);  //Diferencia: su size es p-1, no p
        }
        mergeSort(B);
        mergeSort(C);
        merge(B,C,lista);
    }
}

template<typename T>
void merge(ListaEstatica<T>& B, ListaEstatica<T>& C, ListaEstatica<T>& A)
{
    size_t p = B.size();
    size_t q = C.size();
    size_t n = p + q;
    size_t i = 0, j=0, k = 0;
    while(i < p && j < q)
    {
        if(B[i] <= C[j])
        {
            A[k] = B[i];
            ++i;
        }
        else
        {
            A[k] = C[j];
            ++j;
        }
        ++k;
    }
    if(i == p)
    {
        for(size_t c(j); c < q; c++)
        {
            A[k++] = C[c];
        }
    }
    else
    {
        for(size_t c(i); c < p; c++)
        {
            A[k++] = B[c];
        }
    }
}

template<typename T>
ListaEstatica<T> copy(ListaEstatica<T>& original, size_t begin, size_t end)
{
    ListaEstatica<T> res;
    for(size_t i(begin); i<(end+1);i++)
    {
        res.push_back(original[i]);
    }
    return res;
}

/***
 * Este metodo funciona con diferencias, brechas, gap. Se
 * toma en cuenta una brecha para alinear pares de elementos,
 * estos se comparan entre si, se acomodan dependiendo de su
 * relacion (<,>,=) y la brecha se reduce mas. La clave de este
 * algoritmo es no repetir tantas veces las mismas visitas a los
 * mismos elementos
***/
template<typename T>
void shellSort(ListaEstatica<T>& lista)
{
    size_t gap(lista.size()/2);
    size_t j;
    T temp;
    while(gap > 0)
    {
        for(size_t i(gap); i<lista.size();i++)
        {
            temp = lista[i];
            j = i;
            while(j >= gap && lista[j-gap] > temp)
            {
                lista[j] = lista[j-gap];
                j -= gap;
            }
            lista[j] = temp;
        }
        gap /= 2;
    }
}

/***
 * Similar a ordenar cartas, teniendo una lista vacia de un lado
 * y del otro la original, se toma una de la original y se coloca
 * en su posición con respecto a la lista ordenada.
***/
template<typename T>
void insertionSort(ListaEstatica<T>& lista)
{
    T v;
    int j; //Necesitamos negativos
	for (size_t i(1); i < lista.size(); i++)
	{
        v = lista[i];
		j = i-1;
		while(j >= 0 && lista[j] > v)
		{
		    lista[j+1] = lista[j];
		    --j;
		}
		lista[j+1] = v;
	}
}

/***
 * Recorremos toda la lista de inicio a fin, si encontramos un
 * valor mayor a la izquierda, se intercambian valores. Así se
 * repite hasta que hayamos recorrido la lista n veces, es decir
 * que estemos seguros de haber puesto nuestro dato menor hasta la
 * izquierda
***/
template<typename T>
void bubbleSort(ListaEstatica<T>& lista)
{
    for(size_t i(0); i<lista.size()-1; i++)
    {
        for(size_t j(0);j<lista.size()-i-1; j++)   //Me parecio mas eficiente reducir a n-1-i
        {
            if(lista[j+1]<lista[j])
            {
                swap(lista[j+1],lista[j]);
            }
        }
    }
}

/***
 * Consiste en buscar el mas pequeño y
 * colocarlo al inicio de la lista, así hasta
 * acabar con la lista
***/
template<typename T>
void selectionSort(ListaEstatica<T>& lista)
{
    size_t min;   //Se declara el minimo
    for (size_t i(0); i < lista.size() - 1; ++i)
    {
        min = i;
        for (size_t j(i + 1); j < lista.size(); ++j)
        {
            if (lista[j] < lista[min])
            {
                min = j;
            }
        }
        swap(lista[i],lista[min]);  //Swap integrado en lugar de usar auxiliar
    }
}


#endif // ALGORITMOS_H
