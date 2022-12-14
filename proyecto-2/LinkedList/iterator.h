#ifndef ITERATOR_H
#define ITERATOR_H

#include "nodo.h"
class Iterator
{
private:
    struct nodo* _begin;
    struct nodo* _end;
    struct nodo* _nodo;    
public:
    Iterator(struct nodo* begin, struct nodo* end);
    ~Iterator();
    Iterator& operator++(int);
    Iterator& operator--(int);
    bool hasNext();
    void goToStart();
    struct nodo* begin();
    struct nodo* end();
    struct nodo* nodo(); 
};

#endif