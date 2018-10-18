#pragma once
#include "Person.h"
#include <iostream>
#include <string>

class Matherr  //математическая ошибка вообще

{

public:

	virtual void print() { std::cerr << "MathError\n"; }

};

class Err
{
public:
	virtual void print() { std::cerr << "\nНеизвестная ошибка\n"; }
};

class Noobj : public Err
{
private:
	int index;

public:
	Noobj(int i) : index(i) {}

	void print() { std::cerr << "\nОбъект с данным номером " << index << " не существует.\n"; }
};

class Filerr : public Err
{
	std::string name;
public:
	Filerr(std::string name) { this->name = name; }

	void print() { std::cerr << "\n Файл " << name << " не найден\n";  }
};
//
//class Underflow : public Matherr {}; //потеря значимости
//
//class ZeroDivide : public Matherr   //деление на ноль
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
//	void print() { cerr << "Значение переменной " << str << " = 0" << '\n'; }
//
//};
//
//
//
//class OverFlow : public Matherr  // переполнение разрядной сетки
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
int Sum(int x, int y) throw (OverFlow);  // этой функции разрешается возбуждать только переполнение

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

		cout << "Хотим поймать переполнение на сложении\n";

		cout << "i2="; cin >> i2;

		i3 = Sum(INT_MAX, i2); //если ввести i2 < 0, то все нормально - сложили

		cout << "Сумма INT_MAX + " << i2 << "=" << i3 << '\n';



		cout << "Хотим поймать деление на ноль\n";

		cout << "i2="; cin >> i2;

		i3 = Division(INT_MAX, i2); //если ввести i2 != 0, то все нормально - разделили

		cout << "Разделить INT_MAX / " << i2 << "=" << i3 << '\n';

	}

	catch (Matherr &m) // полиморфизм в действии - объект передается по ссылке, и это будет на самом // деле объект класса OverFlow или объект класса ZeroDivide

	{

		m.print();

	}

}



void f1()

{

	int i3, i2 = INT_MAX;

	try {

		cout << "Хотим поймать переполнение на сложении\n";

		cout << "i2="; cin >> i2;

		i3 = Sum(INT_MAX, i2); //если ввести i2 < 0, то все нормально - сложили

		cout << "Сумма INT_MAX + " << i2 << "=" << i3 << '\n';



		cout << "Хотим поймать деление на ноль\n";

		cout << "i2="; cin >> i2;

		i3 = Division(INT_MAX, i2); //если ввести i2 != 0, то все нормально - разделили

		cout << "Разделить INT_MAX / " << i2 << "=" << i3 << '\n';

	}

	catch (Matherr m) // а вот здесь может быть только объект родительского класса, поэтому для любой                                    // исключительной ситуации будет просто математическая ошибка

	{

		m.print(); // Matherr::print();

	}

}

void workExcp()

{

	try

	{

		int a;

		cout << "\n Число должно быть меньше 5\n";

		cin >> a;

		if (a >= 5) throw a;

		float f;

		cout << "\nЧисло должно быть больше 10\n";

		cin >> f;

		if (f <= 10) throw f;

		float d;

		cout << "\n Деление на ноль\n";

		cin >> d;

		float c = 1;

		if (d == 0) throw ZeroDivide("d");

		cout << c / d;

	}

	catch (int)

	{

		cout << "\nПоймали int!\n";

	}

	catch (float)

	{

		cout << "\nПоймали float!\n";

	}

	catch (ZeroDivide& zd)

	{

		zd.print();

	}

	catch (...)

	{

		cout << "\nПоймали ...\n";

	}

	f();

	f1();

	cout << "\nCorrect!\n";

} */