#include "ADTQueue.h"
#include "Iterador.h"
#include <vector>
#include <iostream>

using namespace std;

class StacksQueue: public ADTQueue
{
private:
    vector<int> *v1;
    vector<int> *v2;
public:
    StacksQueue();
    ~StacksQueue();
    void push(int p);
    void pop();
    int front();
    int size();
    bool empty();
    Iterador begin();
};

