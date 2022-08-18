#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include "ArrayList.h"
#include "LinkedList.h"
#include "List.h"



using namespace std;

void probandoArrayList(){
    List *arr = new ArrayList();
    arr->insert(1);
    arr->insert(2);
    arr->pop();
    arr->pop();
    arr->pop();
    arr->at(3);
    arr->insert(3);
    arr->pop();
    arr->at(1);
    cout<<arr->at(0)<<endl;
    arr->insert(1);
    arr->insert(4);
    arr->insert(9);
    arr->insert(12);
    for(int i = 0; i <arr->size(); i++)
        cout<<arr->at(i)<<endl;
    arr->insert(5);
    arr->at(0);
    arr->at(6);
    arr->insert(7);
    arr->insert(32);
    arr->insert(10);
    for(int i = 0; i < arr->size(); i++)
        cout<<arr->at(i)<<endl;
    arr->pop();
    arr->pop();
    arr->pop();
    arr->pop();
    for(int i = 0; i <arr->size(); i++)
        cout<<arr->at(i)<<endl;
    delete arr;
}

void probandoLinkedList(){
    List *list = new LinkedList();
    list->insert(1);
    list->insert(2);
    list->insert(4);
    list->insert(3);
    list->insert(0);
    cout<<list->at(0)<<endl;
    cout<<list->at(2)<<endl;
    cout<<list->at(4)<<endl;
    cout<<list->at(list->size()-5)<<endl;
    cout<<list->at(1)<<endl;
    cout<<list->at(3)<<endl;
    cout<<list->at(5)<<endl;

    list->insert(1);
    list->insert(2);
    list->pop();
    list->pop();
    list->pop();
    list->at(3);
    list->insert(3);
    list->pop();
    list->at(1);
    cout<<list->at(0)<<endl;
    list->insert(1);
    list->insert(4);
    list->insert(9);
    list->insert(12);
    for(int i = 0; i <list->size(); i++)
        cout<<list->at(i)<<endl;
    list->insert(5);
    list->at(0);
    list->at(6);
    list->insert(7);
    list->insert(32);
    list->insert(10);
    for(int i = 0; i < list->size(); i++)
        cout<<list->at(i)<<endl;
    list->pop();
    list->pop();
    list->pop();
    list->pop();
    for(int i = 0; i <list->size(); i++)
        cout<<list->at(i)<<endl;
    delete list;
}

int main(){
    // probandoArrayList();
    // probandoLinkedList();
    double ALtimeInsert, LCLtimeInsert;
    double ALtimeAt, LCLtimeAt;
    double ALtimePop, LCLtimePop;
    cout << setprecision(numeric_limits<double>::digits10 + 1) << fixed;

    int pow10 = 1000;
    int pow10menos1;
    int rep = 100;
    int aux;
    List *arr;
    List *list;
    clock_t start;


    cout << "\n" << pow10 << " elementos"<<endl << endl;
    ALtimeInsert = ALtimeAt = ALtimePop = 0;
    pow10menos1 = pow10 - 1;

    /*CICLOS "FOR" PARA ARRAYLIST*/
    for(int i = 0; i < rep; i++){
        arr = new ArrayList();

        start = clock();
        for(int j = 0; j < pow10; j++) arr->insert(10); // agrega pow10 veces el entero "10"
        ALtimeInsert += ((double)clock() - (double)start) / CLOCKS_PER_SEC;

        start = clock();
        aux = arr->at(pow10menos1); // busca el ultimo elemento de la lista
        ALtimeAt += ((double)clock() - (double)start) / CLOCKS_PER_SEC;

        start = clock();
        arr->pop(); // elimina el ultimo elemento de la lista
        ALtimePop += ((double)clock() - (double)start) / CLOCKS_PER_SEC;
        delete arr;
    }

    LCLtimeInsert = LCLtimeAt = LCLtimePop = 0;

    /*CICLOS "FOR" PARA LINKEDLIST*/
    for(int i = 0; i < rep; i++){
        list = new LinkedList();
        start = clock();
        for(int j = 0; j < pow10; j++) list->insert(10); // agrega pow10 veces el entero "10"
        LCLtimeInsert += ((double)clock() - (double)start) / CLOCKS_PER_SEC;

        start = clock();
        aux = list->at(pow10menos1); // busca el ultimo elemento de la lista
        LCLtimeAt += ((double)clock() - (double)start) / CLOCKS_PER_SEC;
        
        start = clock();
        list->pop(); // elimina el ultimo elemento de la lista
        LCLtimePop += ((double)clock() - (double)start) / CLOCKS_PER_SEC;
        delete list;
    }


    cout << " A.L. Insert: " << ALtimeInsert/(double)rep << endl;
    cout << "LC.L. Insert: " << LCLtimeInsert/(double)rep << endl << endl;

    cout << "         A.L. At: " << ALtimeAt/(double)rep << endl;
    cout << "        LC.L. At: " << LCLtimeAt/(double)rep << endl << endl;
    
    cout << "            A.L. Pop: " << ALtimePop/(double)rep << endl;
    cout << "           LC.L. Pop: " << LCLtimePop/(double)rep << endl << endl;

    cout << "       A.L. Tiempo total: " << ALtimeInsert/(double)rep + ALtimeAt/(double)rep + ALtimePop/(double)rep<<endl;
    cout << "      LC.L. Tiempo total: " << LCLtimeInsert/(double)rep + LCLtimeAt/(double)rep + LCLtimePop/(double)rep<<endl<<endl<<endl;
}
