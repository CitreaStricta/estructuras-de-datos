#include <bits/stdc++.h>
#include "PriorityQueueHeap.h"
#include "PriorityQueueUnsorted.h"

using namespace std;

// El algoritmo toma O(nlogn)
void HeapSort(vector<int> &vec)
{
	PriorityQueueADT *pqh = new PriorityQueueHeap();

	while(!vec.empty())
	{
		pqh->push(vec.back());
		vec.pop_back();
	}

	while(!pqh->empty())
	{
		vec.push_back(pqh->top());
		pqh->pop();
	}
	delete pqh;
}

// El algoritmo toma O(n^2)
void SelectionSort(vector<int> &vec)
{
	PriorityQueueADT *pqu = new PriorityQueueUnsorted();

	while(!vec.empty())       
	{
		pqu->push(vec.back());
		vec.pop_back();       
	}

	while(!pqu->empty())      
	{
		vec.push_back(pqu->top());
		pqu->pop();
	}
	delete pqu;
}

int main(){
	srand(time(NULL));

	int n = 19;
	vector<int> vecSS;
	for (int i = 0; i < n; i++)
	{
		vecSS.push_back(1 + rand() % n);
	}

	SelectionSort(vecSS);

	vector<int> vecPP;
	for (int i = 0; i < n; i++)
	{
		vecPP.push_back(1 + rand() % n);
	}

	HeapSort(vecPP);
	return 0;
}