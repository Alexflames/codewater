#pragma once
#include "prey.h"

class Fish : public Prey
{
private:
	int age;								// Сколько лет
	string species;							// Вид
	string condition = "нейтральн(-ый)ая";	// Счастлива ли рыба или нет?
	int hungerLevel = 50;					// Скалируется от 0 до 100

public:
	Fish(string species, int age);
	/*
	virtual void swim() = 0;
	virtual void eat() = 0;
	virtual void setFood() = 0;
	*/
	int getAge();
	int getHungerLevel();
	string getCondition();
	void setCondition(string cond);
	void setHungerLevel(int n);
	void updateCondition();					// После любого действия будет проверка на состояние
	virtual void eat(Prey * x) = 0;

private:
	void setSizeBySpecies(string species);	// После создания рыбы будет определён её размер
	void breathe();							// Бульк-бульк
};

