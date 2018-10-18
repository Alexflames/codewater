#include "nonpredatorFish.h"

NonPredatorFish::NonPredatorFish(string species, int age) : Fish(species, age)
{

}

void NonPredatorFish::eat(Prey * x)
{
	if (x->getFoodType() == "plant" && getSize() > x->getSize()) {
		setHungerLevel(getHungerLevel() + 15);
		x->setEaten();
	}
	else 
		setHungerLevel(getHungerLevel() - 5);
	updateCondition();
}	
