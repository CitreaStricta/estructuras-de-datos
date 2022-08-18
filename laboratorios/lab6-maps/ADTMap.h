#ifndef ADTMAP_H
#define ADTMAP_H
#include <iostream>
#include <utility>
#include <string>

using namespace std;

class ADTMap
{
public:
    virtual void insert(pair<string, int>) = 0;
    virtual void erase(string) = 0;
    virtual int at(string) = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
    // sin el metodo siguiente no se puede ejecutar el destructor de los map(s)
    virtual ~ADTMap(){};
    // un buen ejemplo para demostrar esto es
    // 1ero, ejecutar el debugger con un break point dentro del destructor del Map
    // NO TENIENDO este metodo (el debugger NO ENTRARA)
    // 2do, ejecutar el debugger con un break point dentro del destructor del Map
    // TENIENDO este metodo (el debugger SI ENTRARA)
};

#endif