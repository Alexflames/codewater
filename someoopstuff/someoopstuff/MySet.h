#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MySet
{
private:
	vector <int> arrThis;

public:
	MySet();

	void addElementsUsingInput();

	void deleteElementByNumber(int x);

	MySet * intersectWith(MySet * arrB);
	MySet * unionWith(MySet * arrB);
	MySet * differenceWith(MySet * arrB);

	int getNumberOfElements();
	void printElements();

private:
	pair <bool, int> ifElementExists(int x);
};