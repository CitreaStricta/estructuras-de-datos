#include <bits/stdc++.h>
#include "PriorityQueueADT.h"

using namespace std;

class PriorityQueueHeap : public PriorityQueueADT{

private:
	vector<int> _arr;
	void upHeap(int);
	void downHeap(int);
public:
	PriorityQueueHeap();
	~PriorityQueueHeap();
	bool empty();
	int size();
	int top();
	void push(int);
	void pop();
};
