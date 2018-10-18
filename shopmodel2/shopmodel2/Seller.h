#pragma once
#include "Person.h"
#include "ShopQueue.h"
class Seller : public Person
{
private:
	ShopQueue * guestsQueue;
public:
	ShopQueue * getQueue();
	Seller();
	~Seller();
};

