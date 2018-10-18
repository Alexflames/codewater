#include "ClassList.h"

void infoStart() {
	cout << "Добро пожаловать! Здесь вы можете работать со множествами" << endl;
}

void infoInput() {
	cout << endl << "Введите номер множества: ";
}

void infoSets() {
	cout << "Вам доступны следующие множества: " << endl;
}

void infoFuncs() {
	cout << endl << "Введите номер функции, которую хотите использовать (0 - вернуться назад):" << endl
		<< "1 - Создать множество" << endl << "2 - Добавить элементы в множество" << endl
		<< "3 - Удалить множество" << endl << "4 - Удалить элемент по значению из множества " << endl
	    << endl << "Результат следующих функций помещается в новое множество" << endl
		<< "5 - Найти пересечение множеств A и B" << endl << "6 - Найти объединение множеств A и B" << endl
		<< "7 - Найти разность множеств A и B" << endl << "-1 - Выход из программы" << endl;
}

void infoChoice(const int num) {
	cout << endl << "Выбранное множество: множество № " << num << endl;
}

void infosecondSet() {
	cout << endl << "Выберите номер второго множества" << endl;
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
		cout << endl << "Если хотите продолжить добавлять множества, введите 1 (в противном случае - любую другую цифру)" << endl;
		cin >> num;
	}
	int it = 1;

	while (it != -1) {
		infoSets();			// Вывод информации о доступных множествах
		listOfSets->print();

		infoFuncs();		// Информация о доступных функциях
		cin >> it;			// Выбор функции

		switch (it)			// Номера case-ов и их соответствия с функциями можно посмотреть в infoFuncs() в main.cpp
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
			cout << endl << "Введите число, которое будет удалено из выбранного множества" << endl;
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