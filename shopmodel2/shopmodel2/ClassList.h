#pragma once
#include "Seller.h"
#include "Seller.h"
#include "Guest.h"
#include <string> 
#include "myerror.h"
#include <typeinfo>

struct node
{
	Seller* inf;
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
	void push(Seller* x);
	Seller* front();

	Seller* chooseLeastBusy();
	node * operator [] (int i) throw (Noobj);
};
