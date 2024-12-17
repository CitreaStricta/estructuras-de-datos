#include "MapB/MapB.h"
#include "MapG/MapG.h"
#include "MapDH/MapDH.h"

#define mp(x, y)  (make_pair(x, y))

using namespace std;

pair<string, int>* getEntries(int asdf)
{
    pair<string, int> *aux = new pair<string, int>[asdf];
    char f;
    for (int i = 0; i < asdf; i++)
    {
        string s;
        for (int j = 0; j < 6; j++)
        {
            
            f = (char) (97 + rand() % 25); // letras entre a[97] y z[122]
            s.push_back(f);
        }
        
        aux[i] = mp(s, 1 + rand() % 200);
    }
    return aux;
}

void BM(int N)
{
    MapB *m = new MapB(N);
    
    auto *aux = getEntries(N);
    
    for (int i = 0; i < N; i++)
    {
        m->insert(aux[i]);
    }

    for (int i = 0; i < N; i++)
    {
        m->at(aux[i].first);
    }

    cout
    << "BM:\n"
    << "cInsert: " << m->colisionInsert
    << "\ncAt: " << m->colisionAt
    << endl << endl;
    delete[] aux;
    delete m;
}

void GM(int N)
{
    MapG *m = new MapG(N);

    auto *aux = getEntries(N);
    
    for (int i = 0; i < N; i++)
    {
        m->insert(aux[i]);
    }

    for (int i = 0; i < N; i++)
    {
        m->at(aux[i].first);
    }

    cout
    << "GM:\n"
    << "cInsert: " << m->colisionInsert
    << "\ncAt: " << m->colisionAt
    << endl << endl;
    delete[] aux;
    delete m;
}

void DHM(int N)
{
    MapDH *m = new MapDH(N);
    
    auto *aux = getEntries(N);

    for (int i = 0; i < N; i++)
    {
        m->insert(aux[i]);
    }

    for (int i = 0; i < N; i++)
    {
        m->at(aux[i].first);
    }

    cout
    << "DHM:\n"
    << "cInsert: " << m->colisionInsert
    << "\ncAt: " << m->colisionAt
    << endl << endl;
    delete[] aux;
    delete m;
}

int main(int arg, char* argv[])
{
    srand(time(NULL));
    int N = (int) stoi(argv[1]);
    cout << "N igual a " << N << endl << endl;

    if(N < 500)
    {
        cout
        << "Porfavor utiliza un numero "
        << "mayor o igual a 10"
        << endl;
        return 0;
    }

    BM(N);
    GM(N);
    DHM(N);
    
    return 0;
}

