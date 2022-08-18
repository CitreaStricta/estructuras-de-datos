#include "List.h"

class ArrayList : public List {
	private:
		int mysize, capacity;
		int *myarray;
		void agrandar();
	public:
		ArrayList();
		~ArrayList();
		void insert(int n); 
		void pop();
		int at(int pos);
		int size();
};