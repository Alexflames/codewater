#include "deepwaterFish.h"
#include "fish.h"
#include "nonpredatorFish.h"
#include "predatorFish.h"
#include "prey.h"
#include "ClassList.h"
#include "myerror.h"
#include <fstream>

// Приветствие
void infoStart() {
	cout << "Добро пожаловать в морской мир, в данный момент он абсолютно пуст и скучен.\n";
	cout << "Известные океанологам рыбы: losos, okyn, karp, shuka \n";
}
 
// Предлагает ввести тип морского объекта
void infoInput() {
	cout << "Введите тип добавляемого объекта (Fish или plant): ";
}

void infoFish() {
	cout << "\nВведите через пробел сорт рыбы, её возраст (кол-во полных лет): ";
}

// Чем питается, глубоководная ли?
void infoFishType() {												
	cout << "\nВведите 1, если рыба травоядная. 2, если рыба плотоядная. 3, если она глубоководная: ";
}

void infoSeaweed() {
	cout << "\nВведите название того, чем будут питаться рыбы: ";
}

void endInput() {
	cout << "\nВведите 1, если хотите продолжить ввод морских обитателей: ";
}

int main() {
	setlocale(LC_ALL, "Russian");

	string fileName = "input.txt";		// Нужно ввести нужное вам имя файла

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
				cerr << "Введённое число слишком большое";
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
					PredatorFish * toAdd = new PredatorFish(species + "(П)", age);
					sea.push(toAdd);
					break;
				}
				case 3: {
					DeepWaterFish * toAdd = new DeepWaterFish(species + "(Г)", age);
					sea.push(toAdd);
					break;
				}
				default: {
					throw(numberType);
					break;
				}
				}
			}
			catch (...)	// Если введено не число, исключение будет всё равно обработано 
			{
				cerr << "\nВведено не число от 1 до 3! Попробуйте заново.\n";
			}
		}
		else {
			cout << "\nКак это звать?";
			string name; cin >> name;
			Prey * toAdd = new Prey(type, name);
			sea.push(toAdd);
		}
		sea.print();
		endInput();
		cin >> num;
	}

	cout << "\n Введите номер рыбы, которая будет кушать что-то (-1 выход): ";
	cin >> num;
	while (num >= 0) {
		cout << "\n Введите номер морского обитателя - жертвы выбранного существа: ";
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
				cout << "\n Рыба смогла дотянуться до своего хвоста, но кушать отказалась и сказала:\n"
					<< "\"Бог, заставивший меня делать это, сумасшедший\". Баланс природы нарушен так как рыба заговорила. Вы пожалеете об этом!";
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
			cout << "\n Завершение программы \n";
			system("pause");
			return 0;
		}
		
		cout << "\n Введите номер рыбы, которая будет кушать что-то (-1 выход): ";
		cin >> num;
	}

	system("pause");
	return 0;
}