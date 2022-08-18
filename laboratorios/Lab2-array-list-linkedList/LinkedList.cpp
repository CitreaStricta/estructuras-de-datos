#include <iostream>
#include "LinkedList.h"
#include "List.h"

using namespace std;

// La lista se basa en la suposicion de que el puntero del ultimo nodo siempre es NULL
LinkedList::LinkedList(){
    head = NULL;
    mysize = 0;
}

LinkedList::~LinkedList(){
    cout<< "Eliminando objeto(s)..."<<endl;

    nodo *delete_Aux;

    while(head != NULL){
        delete_Aux = head; // [delete_Aux --> head <-- nodo/NULL]
        head = head->siguiente;
        delete_Aux->siguiente = NULL; //No estoy seguro de si esto es necesario.
        // Es para que el puntero del nodo que se va a eliminar no este conectado con el resto de la lista
        delete delete_Aux; // [delete_Aux --> nodo anterior a lo que "head" esta apuntando ahora]
    }
    delete_Aux = NULL;
    mysize = 0;
}

// incerta al principio (en el espacio 1)
void LinkedList::insert(int n){
    //creo un nuevo nodo y lo apunto con aux
    nodo *aux = new nodo(); //[aux --> N_nodo]

    //le entrego 'n' al "int" que el nuevo nodo puede guardar
    aux->n = n; //[aux --> N_nodo.n <-- 3]

    //apunto "siguiente" a lo que "head" esta apuntando
    aux->siguiente = head; //[aux --> N_nodo.siguiente --> head <-- NULL]

    // apunto "head" a lo que "aux" esta apuntando
    head = aux; // head --> aux <-- N_nodo]
    mysize++;
}

// elimina el ultimo elemento
void LinkedList::pop(){
    //Si no hay elementos en la lista
    if(head == NULL){
        cout << "No hay elementos en la lista" << endl;
        return;
    }

    //Si hay mas de 1 elemento en la lista
    if(head->siguiente != NULL){
        //puntero "nodo" creado para "popear" el ultimo elemento
        nodo *pop_ear = head; //[pop_ear --> head <-- nodo]

        while(pop_ear->siguiente->siguiente != NULL)
            pop_ear = pop_ear->siguiente; //[popear --> nodo.siguiente <-- (siguiente nodo)]
        delete pop_ear->siguiente;
        pop_ear->siguiente = NULL;
        mysize--;
        return;
    }

    //Si solo hay un elemento en la lista. (Teoricamente, la lista casi nunca
    //deberia llegar a un punto en donde tenga un solo elemento. Por eso esto esta al final)
    delete head;
    head = NULL;
    mysize--;
}

// Accede al i-esimo elemento de la lista
int LinkedList::at(int pos){
    if(pos > mysize - 1){
        cout <<"La lista no tiene un dato en la pocision " << pos <<endl;
        return -1;
    }

    // Itero el puntero "aux_at" hasta que "aux" sea igual a la posicion buscada
    nodo *aux_at = head;
    while(pos--)
        aux_at = aux_at->siguiente;
    return aux_at->n;
}

// cantidad de elementos almacenados
int LinkedList::size(){
    return mysize;
}
