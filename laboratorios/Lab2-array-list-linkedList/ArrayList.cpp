#include "ArrayList.h"
#include "List.h"
#include <iostream>

using namespace std;

ArrayList::ArrayList(){
    mysize = 0; // cantidad de elementos en el arreglo (NO el indice del ultimo elemento)
    capacity = 1; // largo del arreglo (espacios usados + espacios vacios)
    myarray = new int[capacity];
}

ArrayList::~ArrayList(){
    cout<< "Eliminando objeto(s)..."<<endl;
    delete[] myarray;
    myarray = NULL;
}

void ArrayList::agrandar(){
    capacity *= 2;
    int *aux = new int[capacity];

    int aux_cant = 0;
    while(aux_cant != mysize)
        aux[aux_cant++ + 1] = myarray[aux_cant];

    delete[] myarray;
    myarray = aux;
}

void ArrayList::insert(int n){
    if(capacity == mysize){
        agrandar();
        myarray[0] = n;
        mysize++;
        return;
    }

    int aux = mysize;
    while(aux)
        myarray[aux--] = myarray[aux-1];
    myarray[0] = n;
    mysize++;
}

void ArrayList::pop(){
    if(mysize > 0)
        mysize--;
    else cout<<"El arreglo se encuentra vacio"<<endl;
}

int ArrayList::at(int pos){
    if(pos < mysize) return myarray[pos];
    cout <<"El arreglo no tiene un elemento en esta posicion"<<endl;
    return -1;
}

int ArrayList::size(){
    return mysize;
}
