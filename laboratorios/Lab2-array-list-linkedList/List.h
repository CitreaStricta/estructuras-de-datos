#ifndef LIST_H
#define LIST_H

class List {
	public:
		virtual void insert(int) = 0;
		virtual void pop() = 0;
		virtual int at(int) = 0;
		virtual int size() = 0; 
};

#endif