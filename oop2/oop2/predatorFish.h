#pragma once
#include "fish.h"

class PredatorFish : public Fish
{
private:
	
public:
	PredatorFish(string species, int age);
	void eat(Prey * x);
};