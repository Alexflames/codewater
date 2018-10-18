#include "prey.h"

Prey::Prey(string foodType, string name)
{
	this->foodType = foodType; this->name = name;
}

void Prey::setSize(int num)
{
	size = num;
}

void Prey::setEaten()
{
	eaten = true;
}

bool Prey::ifEaten()
{
	return eaten;
}

int Prey::getSize()
{
	return size;
}

string Prey::getFoodType()
{
	return foodType;
}

string Prey::getName()
{
	return name;
}
