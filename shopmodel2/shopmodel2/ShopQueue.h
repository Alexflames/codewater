#pragma once
#include "myerror.h"
#include "Guest.h"

struct qnode
{
	Guest* inf;
	qnode* prev;
};

class ShopQueue
{
private:
	qnode* head;
	qnode* tail;
	int peopleCount;
public:

	ShopQueue() { head = NULL, tail = NULL; peopleCount = 0; }
	void push(Guest * x);
	Guest* pop() throw (Noobj);
	//void print();		// Символьное представление не требуется
	Guest* front();
	bool isAnyHead();
	int getCount();
};
