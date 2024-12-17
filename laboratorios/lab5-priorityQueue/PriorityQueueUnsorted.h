#include "PriorityQueueADT.h"
#include <vector>

using namespace std;

class PriorityQueueUnsorted : public PriorityQueueADT{

private:
	vector<int> _arr;
	pair<int, int> findMin();
public:
	PriorityQueueUnsorted();
	~PriorityQueueUnsorted();
	bool empty();
	int size();
	int top();
	void push(int);
	void pop();
};
