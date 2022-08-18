#include "List.h"

struct nodo {
	int n;
	nodo *siguiente;
};

class LinkedList: public List {
	private:
		struct nodo *head;
		int mysize;
	public:
		LinkedList();
		~LinkedList();
		void insert(int n);
		void pop();
		int at(int pos);
		int size();
};