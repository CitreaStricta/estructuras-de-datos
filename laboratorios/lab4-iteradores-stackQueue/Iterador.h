#include <iostream>
#include <vector>

using namespace std;

class Iterador
{
private:
    vector<int> *ve;
    vector<int>::iterator it;
public:
    Iterador(vector<int> *v);
    ~Iterador();
    bool hasNext();
    int next();
};