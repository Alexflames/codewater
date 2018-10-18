#include "deepwaterFish.h"
#include "fish.h"
#include "nonpredatorFish.h"
#include "predatorFish.h"
#include "prey.h"
#include "ClassList.h"
#include "myerror.h"
#include <fstream>

// �����������
void infoStart() {
	cout << "����� ���������� � ������� ���, � ������ ������ �� ��������� ���� � ������.\n";
	cout << "��������� ����������� ����: losos, okyn, karp, shuka \n";
}
 
// ���������� ������ ��� �������� �������
void infoInput() {
	cout << "������� ��� ������������ ������� (Fish ��� plant): ";
}

void infoFish() {
	cout << "\n������� ����� ������ ���� ����, � ������� (���-�� ������ ���): ";
}

// ��� ��������, ������������� ��?
void infoFishType() {												
	cout << "\n������� 1, ���� ���� ����������. 2, ���� ���� ����������. 3, ���� ��� �������������: ";
}

void infoSeaweed() {
	cout << "\n������� �������� ����, ��� ����� �������� ����: ";
}

void endInput() {
	cout << "\n������� 1, ���� ������ ���������� ���� ������� ����������: ";
}

int main() {
	setlocale(LC_ALL, "Russian");

	string fileName = "input.txt";		// ����� ������ ������ ��� ��� �����

	try
	{
		ifstream in(fileName);
		if (!in.is_open())
			throw Filerr();
	}
	catch (Err& e)
	{
		e.print();
		if (fileName == "input.txt")
			return 0;
		else
			ifstream in("input.txt");
	}
	ofstream out("output.txt");
	infoStart();													
	MyList sea;
	int num = 1;
	while (num == 1) {
		infoInput();												
		string type;
		cin >> type;

		if (type == "Fish" || type == "fish") {
			infoFish();
			string species; int age;
			cin >> species; 
			try
			{
				cin >> age;
				if (age > INT16_MAX)
					throw (age);
			}
			catch (int)
			{
				cerr << "�������� ����� ������� �������";
				cin >> age;
			}
			infoFishType();
			int numberType;
			try
			{
				cin >> numberType;
				
				switch (numberType)
				{
				case 1: {
					NonPredatorFish * toAdd = new NonPredatorFish(species + "(T)", age);
					sea.push(toAdd);
					break;
				}
				case 2: {
					PredatorFish * toAdd = new PredatorFish(species + "(�)", age);
					sea.push(toAdd);
					break;
				}
				case 3: {
					DeepWaterFish * toAdd = new DeepWaterFish(species + "(�)", age);
					sea.push(toAdd);
					break;
				}
				default: {
					throw(numberType);
					break;
				}
				}
			}
			catch (...)	// ���� ������� �� �����, ���������� ����� �� ����� ���������� 
			{
				cerr << "\n������� �� ����� �� 1 �� 3! ���������� ������.\n";
			}
		}
		else {
			cout << "\n��� ��� �����?";
			string name; cin >> name;
			Prey * toAdd = new Prey(type, name);
			sea.push(toAdd);
		}
		sea.print();
		endInput();
		cin >> num;
	}

	cout << "\n ������� ����� ����, ������� ����� ������ ���-�� (-1 �����): ";
	cin >> num;
	while (num >= 0) {
		cout << "\n ������� ����� �������� ��������� - ������ ���������� ��������: ";
		int numPrey;
		cin >> numPrey;
		try
		{
			node* PredatorInList = sea.operator[](num);
			node* toEatInList = sea.operator[](numPrey);
			if (PredatorInList == NULL || toEatInList == NULL) {
				throw (NULL);
			}
			else if (numPrey == num) {
				cout << "\n ���� ������ ���������� �� ������ ������, �� ������ ���������� � �������:\n"
					<< "\"���, ����������� ���� ������ ���, �����������\". ������ ������� ������� ��� ��� ���� ����������. �� ��������� �� ����!";
				throw (NULL);
			}
			else {
				Prey * Predator = sea.operator[](num)->inf;
				Prey * toEat = sea.operator[](numPrey)->inf;
				Predator->eat(toEat);
				sea.clean();
			}
			sea.print();
		}
		catch (...)
		{
			cout << "\n ���������� ��������� \n";
			system("pause");
			return 0;
		}
		
		cout << "\n ������� ����� ����, ������� ����� ������ ���-�� (-1 �����): ";
		cin >> num;
	}

	system("pause");
	return 0;
}