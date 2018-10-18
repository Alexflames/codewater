#include "MySet.h"

MySet::MySet()
{

}

void MySet::addElementsUsingInput()
{
	cout << endl << "������� ����� �����, ������� ����� ��������� � ���������" << endl;
	string inputS;
	getline(cin, inputS, '\n');
	while (inputS == "")
		getline(cin, inputS, '\n');
	inputS += " ";

	for (int i = 0, substrIt = 0; i < inputS.size(); i++) {
		if (inputS[i] == ' ') {
			if (inputS[i] - 1 == ' ')
				substrIt++;													
			string numToAdd = inputS.substr(substrIt, i - substrIt);

			if (numToAdd.size() > 8) {
				cout << "������� ������� �����! ��������� �� ����� 8 ������! ���������� ��� ���." << endl << endl; 											
				return;
			}

			int numToAddTemp = stoi(numToAdd);									// ���������� ����� � ���������
			
			if (!ifElementExists(numToAddTemp).first)
				arrThis.push_back(numToAddTemp);
			substrIt = i;														// ��������� ����� ����� ���������� ������������� �����
		}
		else if (inputS[i] - '0' < 0 || inputS[i] - '0' > 9) {
			cout << "������� �� �����!" << endl;
			return;
		}
	}
}

void MySet::printElements()
{
	for (int i = 0; i < arrThis.size(); i++) {
		cout << arrThis[i] << " ";
	}
	cout << endl;
}

int MySet::getNumberOfElements()
{										
	return arrThis.size();
}


pair <bool, int> MySet::ifElementExists(int x)
{
	for (int i = 0; i < arrThis.size(); i++) {
		if (arrThis[i] == x) {
			return make_pair(true, i);
		}
	}
	return make_pair(false, NULL);
}

void MySet::deleteElementByNumber(int x)
{
	pair <bool, int> check = ifElementExists(x);
	if (check.first) {
		swap(arrThis[check.second], arrThis[arrThis.size() - 1]);
		arrThis.pop_back();
		cout << "������� \"" << x << "\" �����. " << endl << endl;
	}
	else
		cout << "�������, ������ �������� ��� " << endl << endl;
}

MySet * MySet::intersectWith(MySet * arrB)
{
	MySet * res = new MySet;
	for (int i = 0; i < arrThis.size(); i++) {
		for (int j = 0; j < arrB->arrThis.size(); j++) {
			if (arrThis[i] == arrB->arrThis[j]) {
				res->arrThis.push_back(arrThis[i]);
				break;
			}
		}
	}
	return res;
}

MySet * MySet::unionWith(MySet * arrB)
{
	MySet * res = new MySet;
	for (int i = 0; i < arrThis.size(); i++) {
		res->arrThis.push_back(arrThis[i]);
	}
	for (int i = 0; i < arrB->arrThis.size(); i++) {
		if (!ifElementExists(arrB->arrThis[i]).first)
			res->arrThis.push_back(arrB->arrThis[i]);
	}
	return res;
}

MySet * MySet::differenceWith(MySet * arrB)
{
	MySet * res = new MySet;
	for (int i = 0; i < arrThis.size(); i++) {
		if (!arrB->ifElementExists(arrThis[i]).first)
			res->arrThis.push_back(arrThis[i]);
	}
	return res;
}
