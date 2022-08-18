#ifndef MB_H
#define MB_H

#include "../ADTMap.h"
// indica que se uso, pero que ahora esta
// disponible para colocar algo nuevo
#define AVAILABLE make_pair("#%$2", -1)
// indica que nunca que ha usado
#define EMPTY make_pair("", 0)


class MapB : public ADTMap
{
private:
    pair<string, int> *mapa;
    // tamanio del map
    int N;
    // cantidad de elementos en el map
    int _cant;
    // factor de carga del map
    float fCarga = 0.5;
    int h(string);
    int ch(int);
    int hFunction(string);
    int colission_handler(string);
    int searching(string);
    void rehash();
public:
    int colisionInsert = 0;
    int colisionAt = 0;
    MapB(int);
    ~MapB();
    void insert(pair<string, int>);
    void erase(string);
    int at(string);
    int size();
    bool empty();
};

#endif