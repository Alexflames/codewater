#pragma once
#include <iostream>
#include <string>

using namespace std;

// �� ����� �� ����� ����� ���� ����� ��� ������ �������

class Prey
{
private:
	string foodType;							// �������� ����� ��� ������?
	string name = "unknown tasty object";		// ��� ����� ���� ������
	int size = 3;								// ��� �������� ����� �������
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
	virtual string getCondition() { return "�� ����"; }; // ������� � ���
	virtual int getHungerLevel() { return 99999; }
};
