#ifndef MDH_H
#define MDH_H

#include "../ADTMap.h"
// indica que se uso, pero que ahora esta
// disponible para colocar algo nuevo
#define AVAILABLE make_pair("#%$2", -1)
// indica que nunca que ha usado
#define EMPTY make_pair("", 0)


class MapDH : public ADTMap
{
private:
    pair<string, int> *mapa;
    // tamanio del map
    int N;
    // cantidad de elementos en el map
    int _cant;
    // factor de carga del map
    float fCarga = 0.5;
    int hFunction(string);
    int h(string);
    int comp_h(int);
    int dFunction(string);
    int d(string);
    int comp_d(int);
    int colission_handler(string);
    int searching(string);
    void rehash();
public:
    int colisionInsert = 0;
    int colisionAt = 0;
    MapDH(int);
    ~MapDH();
    void insert(pair<string, int>);
    void erase(string);
    int at(string);
    int size();
    bool empty();
};

#endif