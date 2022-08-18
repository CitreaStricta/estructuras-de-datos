#include "MapDH.h"

// si PH "PRINT_HELP" se define como "true"
// ayuda por consola para ver lo que esta ocurriendo
// aparecera
#define ph !true

// true si se quiere contar la cantidad de colisiones de
// insert y at (no usar erese si se quiere medir esto)
#define count true

MapDH::MapDH(int n)
{
    N = n/2 - 1;
    mapa = new pair<string, int>[N];
    _cant = 0;
}

MapDH::~MapDH()
{
    delete[] mapa;
}

// si una llave ya esta y se trata de meter denuevo, no
void MapDH::insert(pair<string, int> p)
{
    if(ph) cout << endl;
    int inserting = colission_handler(p.first);

        // si la llave en "inserting" es igual a la llave que
        // se esta tratando de insertar
        if(mapa[inserting].first == p.first)
        {   // cambiemos el valor de esta a p.second
            if(ph) cout
            << "se encontro la llave buscada en el rango: " << inserting
            << "\ncambiando su valor a " << p.second
            << endl;
            mapa[inserting].second = p.second;
            return;
        }

    if(ph) cout << "hasheado a: " << inserting << endl;
    mapa[inserting] = p;
    _cant++;
    rehash();
}

void MapDH::erase(string s)
{
    if(ph) cout << endl;
    int _toDelete = searching(s);
    if(_toDelete == -1)
    {
        return;
    }

    if(ph) cout <<"eliminado lo de: " << _toDelete << endl;
    mapa[_toDelete] = AVAILABLE;
    _cant--;
}

// retorna el valor de la llave
int MapDH::at(string s)
{
    if(ph) cout << endl;
    int searched = searching(s);

    if(searched == -1)
    {
        return searched;
    }

    if(ph) cout << "encontrado en: " << searched << endl;
    return mapa[searched].second;
}

int MapDH::size()
{
    if(ph) cout << endl;
    return _cant;
}

bool MapDH::empty()
{
    if(_cant) return false;
    return true;
}

int MapDH::hFunction(string s)
{
    return comp_h(h(s));
}

// la funcion retorna un int que indica la posicion en la
// tabla hash (retorna numeros de [0 a (N - 1)])
int MapDH::h(string s)
{
    unsigned int hashInt = 0;

    // Poly accum
    int z = 33;
    unsigned int pow_Of_z = 1;

    for (int i = 0; i < s.length(); i++)
    {
        hashInt += (((int) s[i] - 97) * pow_Of_z) % N;
        pow_Of_z *= z;
    }

    if(ph) cout
    << "h() valor de "
    << "'" << s << "'"
    << " antes de la compresion: "
    << hashInt
    << endl;
    return hashInt;
}

// funcion de compresion
int MapDH::comp_h(int hashInt)
{
    int hashTo = hashInt % N;
    return hashTo;
}

int MapDH::dFunction(string s)
{
    return comp_d(d(s));
}

int MapDH::d(string s)
{
    unsigned int hashInt = 0;

    // Poly accum
    int z = 97;
    unsigned int pow_Of_z = 1;

    for (int i = 0; i < s.length(); i++)
    {
        hashInt += (((int) s[i] - 97) * pow_Of_z) % N;
        pow_Of_z *= z;
    }

    if(ph) cout
    << "d() valor de "
    << "'" << s << "'"
    << " antes de la compresion: "
    << hashInt
    << endl;
    return hashInt;
}

int MapDH::comp_d(int hashInt) 
{
    unsigned int hashTo = 67 - (hashInt % 67);
    return hashTo;
}

int MapDH::colission_handler(string s)
{
    int j = 0;
    unsigned int h1 = hFunction(s);
    unsigned int h2 = dFunction(s);
    unsigned int _toInsert = h1;

    bool vacant = false;
    int here;

    if(ph) cout <<"intentando hashear a: " << _toInsert << endl;
    while(true)
    {
        // si la llave es igual a "" entonces
        // no se debe buscar mas y se debe insertar aqui
        if(mapa[_toInsert].first == "") break;

        // si es igual a "#%$2" entonces
        // guarda la 1era ocurrencia de este caso y continua
        if(mapa[_toInsert].first == "#%$2" && !vacant)
        {
            here = _toInsert;
            vacant = true;
        }

        // si es igual a la misma llave entonces
        // se debe retornar la pocision de esta llave
        if(mapa[_toInsert].first == s)
        {
            vacant = false;
            break;
        }

        // si no se encontro un espacio vacio, ni disponible, ni la misma llave,
        // entonces revisa en el siguiente espacio
        // (por la naturaleza circular que necesitamos, decimos)
        if(count) colisionInsert++;
        j++;
        _toInsert = (h1 + j*h2) % N;
    }    
    
    if(vacant) return here;
    return _toInsert;
}

int MapDH::searching(string s)
{   
    int j = 0;
    unsigned int h1 = hFunction(s);
    unsigned int h2 = dFunction(s);
    unsigned int _toSearch = h1;
    if(ph) cout <<"buscando en: " << _toSearch << endl;
    
    // no existe la posibilidad de que no se encuentre un espacio vacio si es que lo hay.
    // Pero existe la posibilidad de que todos los espacios hayan sido usados
    // almenos 1 vez. Esto provocaria que nunca encontremos un espacio vacio ya que
    // todos estan siendo usado por "AVAILABLE" o por llaves que no son la que buscamos!
    // Coloquemos una condicion de detencion para el while:
    // si se da una vuelta completa al mapa, el while se detiene
    // y retorna -1 ya que la llave no fue encontrada
    int i = 0;
    while(i++ != N)
    {
        // si las llaves son iguales
        if(mapa[_toSearch].first == s)
        {   // entonces retornamos este
            return _toSearch;
        }

        // si la llave es igual a ""
        // entonces retornar -1
        if(mapa[_toSearch].first == "")
        {       
            if(ph) cout
            << "la llave no fue encontrada\n"
            << "se llego hasta: " << _toSearch
            << "\nantes de concluir la busqueda"
            << endl;
            return -1;
        }

        // si no se encontro un espacio vacio
        // entonces revisa en el siguiente espacio
        // (por la naturaleza circular que necesitamos, decimos)
        if(count) colisionAt++;
        j++;
        _toSearch = ((h1 + j*h2)) % N;
    }
       
    if(ph) cout
    << "la llave no fue encontrada\n"
    << "se llego hasta: " << _toSearch
    << "\nantes de concluir la busqueda"
    << endl;
    return -1;
}

void MapDH::rehash()
{
    if(ph) cout << (float)size()/(float)N << endl;

    if(fCarga > (float)size()/(float)N) return;

    if(ph) cout << "\nrehasheando..." << endl;

    _cant = 0;

    // creo un nuevo puntero que apunte a la tabla vieja
    // y al puntero viejo lo apunto a una tabla nueva
    // con el doble del tamanio de la vieja
    pair<string, int> *vMapa = mapa;
    // tamanio viejo
    int vN = N;
    // tamanio nuevo
    N = 2*N;
    mapa = new pair<string, int>[N];

    // de esta forma, puedo utilizar todos los metodos anteriores
    // que estan hechos para funcionar con el array que
    // el puntero "mapa" esta apuntando
    pair<string, int> pairHandler;
    for (int i = 0; i < vN; i++)
    {
        pairHandler = vMapa[i];
        if(pairHandler.first != "#%$2" &&
           pairHandler.first != "")
        {
            insert(pairHandler);
        }
    }

    delete[] vMapa;

    if(ph) cout
    << "rehash finalizado"
    << endl;
}
