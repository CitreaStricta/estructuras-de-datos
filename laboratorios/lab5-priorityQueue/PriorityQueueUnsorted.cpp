#include <bits/stdc++.h>
#include "PriorityQueueUnsorted.h"

using namespace std;

// Complegidad es O(1)
PriorityQueueUnsorted::PriorityQueueUnsorted(){}

// Complegidad es O(1)
PriorityQueueUnsorted::~PriorityQueueUnsorted(){}

// Complegidad es O(n)
pair<int, int> PriorityQueueUnsorted::findMin()
{
    pair<int, int> auxP;
    auxP = make_pair(0, _arr[0]);
    for (int i = 1; i < _arr.size(); i++)
    {
        if(auxP.second > _arr[i])
        {// si hay [2+] elementos mas pequenios, el 1ero en haber entrado saldra
            auxP.first = i;
            auxP.second = _arr[i];
        }
    }
    return auxP;
}

// Complegidad es O(1)
bool PriorityQueueUnsorted::empty()
{
    return _arr.empty();
}

// Complegidad es O(1)
int PriorityQueueUnsorted::size()
{
    return _arr.size();
}

// Complegidad es O(1) [O(n) si se considera findMin()]
int PriorityQueueUnsorted::top()
{
    if(_arr.size())
    {
        return findMin().second;
    }
    cout << "El arreglo esta vacio" << endl;
    return -1;
}

// Complegidad es O(1)
void PriorityQueueUnsorted::push(int n)
{
    _arr.push_back(n);
}

// Complegidad es O(1) [O(n) si se considera findMin()]
void PriorityQueueUnsorted::pop()
{
    if(empty())
    {
        cout << "El vector esta vacio" << endl;
        return;
    }
    // como el orden no importa, puedo simplemente mandar el menor
    // de los elementos al final del vector y, acto seguido, popearlo
    // para evitar que el arreglo quede con espacios vacios
    pair<int, int> auxP = findMin();
    _arr[auxP.first] = _arr.back();
    _arr.back() = auxP.second;
    _arr.pop_back();
}