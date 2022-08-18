#include "StacksQueue.h"

StacksQueue::StacksQueue()
{
    v1 = new vector<int>();
    v2 = new vector<int>();
};

StacksQueue::~StacksQueue()
{
    delete v1;
    delete v2;
};

void StacksQueue::push(int p)
{
    while(!v2->empty())
    {
        v1->push_back(v2->back());
        v2->pop_back();
    }
    v1->push_back(p);
};

int StacksQueue::size()
{
    return v1->size() +
           v2->size();
};

bool StacksQueue::empty()
{
    if(size())
    {
        return false;
    }
    return true;
};

void StacksQueue::pop()
{
    if(empty())
        return;
    if(v2->empty())
    {
        while(!v1->empty())
        {
            v2->push_back(v1->back());
            v1->pop_back();
        }
    }
    v2->pop_back();
	return;
};

int StacksQueue::front()
{
    if(empty())
        return -1;
    if(v2->empty())
    {
        while(!v1->empty())
        {
            v2->push_back(v1->back());
            v1->pop_back();
        }
    }
    return v2->back();
    
};

Iterador StacksQueue::begin()
{
    // while para vaciar los elementos de v2 en v1 y poder iterar solo en v1
    while(!v2->empty())
    {
        v1->push_back(v2->back());
        v2->pop_back();
    }

    Iterador it = Iterador(v1);
    return it;
}