#pragma once
#include "prey.h"

class Fish : public Prey
{
private:
	int age;								// ������� ���
	string species;							// ���
	string condition = "���������(-��)��";	// ��������� �� ���� ��� ���?
	int hungerLevel = 50;					// ����������� �� 0 �� 100

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
	void updateCondition();					// ����� ������ �������� ����� �������� �� ���������
	virtual void eat(Prey * x) = 0;

private:
	void setSizeBySpecies(string species);	// ����� �������� ���� ����� �������� � ������
	void breathe();							// �����-�����
};

