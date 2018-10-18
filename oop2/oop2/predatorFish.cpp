#include "predatorFish.h"

PredatorFish::PredatorFish(string species, int age) : Fish(species, age)
{

}

void PredatorFish::eat(Prey * x)
{
	int predatorSize = getSize();
	int xSize = x->getSize();
	if (x->getFoodType() == "fish" && predatorSize > xSize) {
		setHungerLevel(getHungerLevel() + xSize);
		x->setEaten();
	}
	else
		setHungerLevel(getHungerLevel() - 5);
	updateCondition();
}
