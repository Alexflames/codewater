#pragma once
#include "Person.h"
#include <cstdlib>

class Guest : public Person
{
private:
	bool consulted;
	int money;
public:
	Guest(int fromMoney, int toMoney);
	int getMoney();
	bool isConsulted();
	void justConsulted();
	~Guest();
private:
	void setConsultNeed();
	void setRandomStartingMoney(int fromMoney, int toMoney);
};

