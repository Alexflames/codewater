#pragma once
#include "Person.h"
#include <iostream>
#include <string>

class Matherr  //�������������� ������ ������

{

public:

	virtual void print() { std::cerr << "MathError\n"; }

};

class Err
{
public:
	virtual void print() { std::cerr << "\n����������� ������\n"; }
};

class Noobj : public Err
{
private:
	int index;

public:
	Noobj(int i) : index(i) {}

	void print() { std::cerr << "\n������ � ������ ������� " << index << " �� ����������.\n"; }
};

class Filerr : public Err
{
	std::string name;
public:
	Filerr(std::string name) { this->name = name; }

	void print() { std::cerr << "\n ���� " << name << " �� ������\n";  }
};
//
//class Underflow : public Matherr {}; //������ ����������
//
//class ZeroDivide : public Matherr   //������� �� ����
//
//{
//
//private:
//
//	string str;
//
//public:
//
//	ZeroDivide(string s) : str(s) {}
//
//	void print() { cerr << "�������� ���������� " << str << " = 0" << '\n'; }
//
//};
//
//
//
//class OverFlow : public Matherr  // ������������ ��������� �����
//
//{
//
//	string str;
//
//	int a1, a2;
//
//public:
//
//	OverFlow(string s, int a, int b) :str(s), a1(a), a2(b) {}
//
//	void print() { cerr << str << a1 << ", " << a2 << '\n'; }
//
//};
/*
int Sum(int x, int y) throw (OverFlow);  // ���� ������� ����������� ���������� ������ ������������

int Sum(int x, int y)

{

	if (x>INT_MAX - y) throw OverFlow("+", x, y);

	return x + y;

}

int Division(int x, int y) throw (ZeroDivide);

int Division(int x, int y)
{
	if (y == 0) throw ZeroDivide("y");
	return x / y;
}

void f()

{

	int i3, i2 = INT_MAX;

	try {

		cout << "����� ������� ������������ �� ��������\n";

		cout << "i2="; cin >> i2;

		i3 = Sum(INT_MAX, i2); //���� ������ i2 < 0, �� ��� ��������� - �������

		cout << "����� INT_MAX + " << i2 << "=" << i3 << '\n';



		cout << "����� ������� ������� �� ����\n";

		cout << "i2="; cin >> i2;

		i3 = Division(INT_MAX, i2); //���� ������ i2 != 0, �� ��� ��������� - ���������

		cout << "��������� INT_MAX / " << i2 << "=" << i3 << '\n';

	}

	catch (Matherr &m) // ����������� � �������� - ������ ���������� �� ������, � ��� ����� �� ����� // ���� ������ ������ OverFlow ��� ������ ������ ZeroDivide

	{

		m.print();

	}

}



void f1()

{

	int i3, i2 = INT_MAX;

	try {

		cout << "����� ������� ������������ �� ��������\n";

		cout << "i2="; cin >> i2;

		i3 = Sum(INT_MAX, i2); //���� ������ i2 < 0, �� ��� ��������� - �������

		cout << "����� INT_MAX + " << i2 << "=" << i3 << '\n';



		cout << "����� ������� ������� �� ����\n";

		cout << "i2="; cin >> i2;

		i3 = Division(INT_MAX, i2); //���� ������ i2 != 0, �� ��� ��������� - ���������

		cout << "��������� INT_MAX / " << i2 << "=" << i3 << '\n';

	}

	catch (Matherr m) // � ��� ����� ����� ���� ������ ������ ������������� ������, ������� ��� �����                                    // �������������� �������� ����� ������ �������������� ������

	{

		m.print(); // Matherr::print();

	}

}

void workExcp()

{

	try

	{

		int a;

		cout << "\n ����� ������ ���� ������ 5\n";

		cin >> a;

		if (a >= 5) throw a;

		float f;

		cout << "\n����� ������ ���� ������ 10\n";

		cin >> f;

		if (f <= 10) throw f;

		float d;

		cout << "\n ������� �� ����\n";

		cin >> d;

		float c = 1;

		if (d == 0) throw ZeroDivide("d");

		cout << c / d;

	}

	catch (int)

	{

		cout << "\n������� int!\n";

	}

	catch (float)

	{

		cout << "\n������� float!\n";

	}

	catch (ZeroDivide& zd)

	{

		zd.print();

	}

	catch (...)

	{

		cout << "\n������� ...\n";

	}

	f();

	f1();

	cout << "\nCorrect!\n";

} */