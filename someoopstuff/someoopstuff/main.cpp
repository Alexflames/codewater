#include "ClassList.h"

void infoStart() {
	cout << "����� ����������! ����� �� ������ �������� �� �����������" << endl;
}

void infoInput() {
	cout << endl << "������� ����� ���������: ";
}

void infoSets() {
	cout << "��� �������� ��������� ���������: " << endl;
}

void infoFuncs() {
	cout << endl << "������� ����� �������, ������� ������ ������������ (0 - ��������� �����):" << endl
		<< "1 - ������� ���������" << endl << "2 - �������� �������� � ���������" << endl
		<< "3 - ������� ���������" << endl << "4 - ������� ������� �� �������� �� ��������� " << endl
	    << endl << "��������� ��������� ������� ���������� � ����� ���������" << endl
		<< "5 - ����� ����������� �������� A � B" << endl << "6 - ����� ����������� �������� A � B" << endl
		<< "7 - ����� �������� �������� A � B" << endl << "-1 - ����� �� ���������" << endl;
}

void infoChoice(const int num) {
	cout << endl << "��������� ���������: ��������� � " << num << endl;
}

void infosecondSet() {
	cout << endl << "�������� ����� ������� ���������" << endl;
	infoSets();
}
 
int main() {
	setlocale(LC_ALL, "Russian");
	infoStart();

	int num = 1;
	MyList * listOfSets = new MyList;
	while (num == 1) {
		vector <int> temp;
		MySet * newSet = new MySet;
		newSet->addElementsUsingInput();
		listOfSets->push(newSet);
		infoSets();
		listOfSets->print();
		cout << endl << "���� ������ ���������� ��������� ���������, ������� 1 (� ��������� ������ - ����� ������ �����)" << endl;
		cin >> num;
	}
	int it = 1;

	while (it != -1) {
		infoSets();			// ����� ���������� � ��������� ����������
		listOfSets->print();

		infoFuncs();		// ���������� � ��������� ��������
		cin >> it;			// ����� �������

		switch (it)			// ������ case-�� � �� ������������ � ��������� ����� ���������� � infoFuncs() � main.cpp
		{
		case 1: {
			vector <int> temp;
			MySet * newSet = new MySet;
			newSet->addElementsUsingInput();
			listOfSets->push(newSet);
			break;
		}
		case 2: {
			infoInput();
			int itSet;
			cin >> itSet;
			infoChoice(itSet);
			node * whereitis = listOfSets->operator[](itSet);
			whereitis->inf->addElementsUsingInput();
			break;
		}
		case 3: {
			infoInput();
			int itSet;
			cin >> itSet;
			infoChoice(itSet);
			node * whereitis = listOfSets->operator[](itSet);
			listOfSets->deleteThisNode(whereitis);
			break;
		}
		case 4: {
			infoInput();
			int itSet;
			cin >> itSet;
			infoChoice(itSet);
			node * whereitis = listOfSets->operator[](itSet);
			cout << endl << "������� �����, ������� ����� ������� �� ���������� ���������" << endl;
			int x;
			cin >> x;
			whereitis->inf->deleteElementByNumber(x);
			break;
		}
		case 5: {
			infoInput(); cout << "(A) ";
			int itSet;
			cin >> itSet;
			infoChoice(itSet);
			node * whereitisA = listOfSets->operator[](itSet);
			infoInput(); cout << "(B) ";
			cin >> itSet;
			infoChoice(itSet);
			node * whereitisB = listOfSets->operator[](itSet);
			listOfSets->push(whereitisA->inf->intersectWith(whereitisB->inf));
			break;
		}
		case 6: {
			infoInput(); cout << "(A) ";
			int itSet;
			cin >> itSet;
			infoChoice(itSet);
			node * whereitisA = listOfSets->operator[](itSet);
			infoInput(); cout << "(B) ";
			cin >> itSet;
			infoChoice(itSet);
			node * whereitisB = listOfSets->operator[](itSet);
			listOfSets->push(whereitisA->inf->unionWith(whereitisB->inf));
			break;
		}
		case 7: {
			infoInput(); cout << "(A) ";
			int itSet;
			cin >> itSet;
			infoChoice(itSet);
			node * whereitisA = listOfSets->operator[](itSet);
			infoInput(); cout << "(B) ";
			cin >> itSet;
			infoChoice(itSet);
			node * whereitisB = listOfSets->operator[](itSet);
			listOfSets->push(whereitisA->inf->differenceWith(whereitisB->inf));
			break;
		}
		default:
			break;
		}
	}
	return 0;
}