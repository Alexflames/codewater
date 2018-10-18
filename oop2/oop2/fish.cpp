#include "fish.h"

Fish::Fish(string species, int age) : Prey("fish", species)
{
	this->species = species; this->age = age;
	setSizeBySpecies(species);
}

int Fish::getAge()
{
	return age;
}

int Fish::getHungerLevel()
{
	return hungerLevel;
}

string Fish::getCondition()
{
	return condition;
}

void Fish::setCondition(string cond)
{
	condition = cond;
}

void Fish::setHungerLevel(int n)
{
	hungerLevel = n;
}

void Fish::setSizeBySpecies(string species)
{
	if (species == "losos")
		setSize(50 * age);
	else if (species == "okyn" || species == "karp")
		setSize(25 * age);
	else if (species == "shuka")
		setSize(100 * age);
	else
		setSize(20 * age);
}

void Fish::breathe()
{
	cout << condition << species << " дышит. \"...\"(Бульк)";
}

// После любого действия будет изменение состояния
void Fish::updateCondition()
{
	if (getHungerLevel() > 100) {
		setCondition("сытая!");
		hungerLevel = 100;
	}
	else if (getHungerLevel() < 0) {
		setCondition("голодная..");
		hungerLevel = 0;
	}
}

