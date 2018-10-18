#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

/*
	z-функция:
	Каждый i-ый элемент итогового массива -
	Наибольшое число символов начиная с позиции i, 
	совпадающих с первыми символами строки s.
	Эффективная реализация.

	Сопоставляем первому элементу ноль
*/
vector<int> z_function(string s) {
	int n = s.length();
	vector<int> z(n);							 // отрезок совпадения изначально [0, 0]
	for (int i = 1, l = 0, r = 0; i < n; i++) {  // l - левая  часть рассматриваемого отрезка
												 // r - правая часть рассматриваемого отрезка
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);     
		while (z[i] + i < n && s[z[i]] == s[z[i] + i]) // проверка совпадения
			z[i]++;
		if (i + z[i] - 1 > r)					 // для эффективного прохода по следующим символам
			l = i, r = i + z[i] - 1;             // и избежания лишних проверок
	}
	return z;
}

int main() {
	setlocale(LC_ALL, "russian");
	time_t thistime = time(NULL);
	srand(time(&thistime));

#pragma region инициализация исходного массива
	int n;
	int switch_num;
	cout << "Enter 1 to input string manually (Default = 0 = auto)" << endl;
	cin >> switch_num;
	string strToBePrefixed = "";
	switch (switch_num)
	{
	case 1:
		cout << "Enter the string" << endl;
		cin >> strToBePrefixed;
		break;
	default:
		int strLength;
		cout << "enter the length of the string \n";
		cin >> strLength;
		for (int i = 0; i < strLength; i++) {
			char input_char = rand() % 26 + 'a';
			strToBePrefixed += input_char;
		}
		cout << endl << strToBePrefixed << endl;
		break;
	}
	
#pragma endregion

	//int startAlg = clock();	// Начало

	//int endAlg = clock();	// Конец
	//out << "Time passed since algorithm's start (in m/s): " << endAlg - startAlg << endl;
	
	vector <int> result = z_function(strToBePrefixed);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}

	cout << endl;

	system("pause");
	return 0;
}