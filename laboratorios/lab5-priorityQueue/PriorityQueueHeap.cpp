#include <iostream>
#include "PriorityQueueHeap.h"

using namespace std;

// Complegidad es O(1)
PriorityQueueHeap::PriorityQueueHeap()
{
    _arr.push_back(0); // el indice 0 nunca se usa
}

// Complegidad es O(1)
PriorityQueueHeap::~PriorityQueueHeap(){}

// Complegidad es O(logn)
void PriorityQueueHeap::upHeap(int n)
{   // si llega a la raiz
    if(n == 1) return;
    // si es hijo izquierdo
    if(n % 2 == 0)
    {   // si el hijo es menor o igual al padre
        if(_arr[n] <= _arr[n/2])
        {   // entonces swapea el hijo con el padre
            std::swap(_arr[n], _arr[n/2]);
            // y vuelve a revisar con upHeap
            return upHeap(n/2);
        }
        return;
    }
    // si es hijo derecho
    if(n % 2 == 1)
    {   // si el hijo es menor o igual al padre
        if(_arr[n] <= _arr[(n-1)/2])
        {   // entonces swapea el hijo con el padre
            std::swap(_arr[n], _arr[(n-1)/2]);
            // y vuelve a revisar con upHeap
            return upHeap((n-1)/2);
        }
        return;
    }

    // nunca deberia llegar aqui
    cout << "Error upHeap" << endl;
    exit(1);
}

// Complegidad es O(logn)
void PriorityQueueHeap::downHeap(int n)
{   // si el hijo izquierdo no existe
    if(2*n > size()) return;
    // si existe un hijo derecho
    if(2*n + 1 <= size())
    {   // si el hijo izquierdo es menor al derecho
        if(_arr[2*n] < _arr[2*n + 1])
        {   // si el padre es mayor al hijo
            if (_arr[n] >= _arr[2*n])
            {   // swap padre con el izquierdo
                std::swap(_arr[n], _arr[2*n]);
                // y vuelve a revisar con downHeap
                return downHeap(2*n);
            }
        }
    }
    // si no hay hijo derecho
    else
    {   // si el padre es mayor al hijo
        if (_arr[n] > _arr[2*n])
        {   // swap padre con el izquierdo
            std::swap(_arr[n], _arr[2*n]);
            // y vuelve a revisar con downHeap
            return downHeap(2*n);
        }
        // si el padre es menor o igual al hijo
        else return;
    }

    // si el hijo derecho es menor o igual al izquierdo
    if(_arr[2*n + 1] <= _arr[2*n])
    {   // si el padre es mayor al hijo
        if (_arr[n] > _arr[2*n + 1])
        {   // swap padre con el izquierdo
            std::swap(_arr[n], _arr[2*n + 1]);
            // y vuelve a revisar con downHeap
            return downHeap(2*n + 1);
        }
        // si el padre es menor o igual al hijo
        else return;
    }

    // nunca deberia llegar aqui
    cout << "Error downHeap" << endl;
}

// Complegidad es O(1)
bool PriorityQueueHeap::empty()
{
    if(size()) return false;
    return true;
}

// Complegidad es O(1)
int PriorityQueueHeap::size()
{   // el 1er indice del arreglo no se usa
    // por lo tanto el largo del tree siempre
    // es menor por 1
    return (_arr.size() - 1);
}

// Complegidad es O(1)
int PriorityQueueHeap::top()
{
    if(size())
    {
        return _arr[1];
    }
    cout << "El arreglo esta vacio" << endl;
    return -1;
}

// Complegidad es O(1) (O(logn) si se considera upHeap) 
void PriorityQueueHeap::push(int n)
{
    _arr.push_back(n);
    upHeap(size());
}

// Complegidad es O(1) (O(logn) si se considera downHeap)
void PriorityQueueHeap::pop()
{
    std::swap(_arr[1], _arr.back());
    _arr.pop_back();
    downHeap(1);
}
