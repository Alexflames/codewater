#pragma once
#include "fish.h"

// ���������� ����
class NonPredatorFish : public Fish
{
public:
	NonPredatorFish(string species, int age);
	void eat(Prey * x);
};