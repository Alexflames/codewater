#pragma once
#include "prey.h"
#include "fish.h"
#include "myerror.h"
#include "Person.h"

struct node
{
	Person* inf;
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
	void push(Prey* x);
	void print();
	void deleteThisNode(node * x);
	void clean();
	Prey* front();

	node * operator [] (int i) throw (Noobj);
};
