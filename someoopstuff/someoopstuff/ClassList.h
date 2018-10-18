#pragma once
#include "MySet.h"

struct node 
{
	MySet* inf;
	node* next;
	node* prev;
};

class MyList 
{
private:
	node* head;
	node* tail;
public:
	MyList() { head = NULL, tail = NULL; }
	void push(MySet* x);
	void print();
	void deleteThisNode(node * x);

	node * operator [] (int i);
};
