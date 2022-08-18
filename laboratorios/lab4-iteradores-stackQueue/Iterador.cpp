#include "Iterador.h"

Iterador::Iterador(vector<int> *v)
{
    ve = v;
    it = ve->begin();
};

Iterador::~Iterador(){};

bool Iterador::hasNext()
{
    // "hasNext" ahora se asegura de que
    // el que actualmente se esta revisando no sea el end()
    // si lo es, entonces "no tiene un siguiente" y devuelve "false"
    if(it != ve->end())
       return true;
    return false;
}

int Iterador::next()
{
    it++;
    return *(it-1);
};