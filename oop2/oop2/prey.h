#pragma once
#include <iostream>
#include <string>

using namespace std;

// Всё живое на Земле может быть пищей для других существ

class Prey
{
private:
	string foodType;							// Является рыбой или травой?
	string name = "unknown tasty object";		// Как звать этот объект
	int size = 3;								// Для поедания этого объекта
	bool eaten = false;
public:
	Prey(string foodType, string name);
	void setSize(int num);
	void setEaten();
	bool ifEaten();
	int getSize();
	string getFoodType();
	string getName();
	virtual void eat(Prey * x){};
	virtual string getCondition() { return "НЕ РЫБА"; }; // Имеется у рыб
	virtual int getHungerLevel() { return 99999; }
};
