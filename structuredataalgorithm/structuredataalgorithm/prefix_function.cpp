#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

/*
	Префикс-функция:
	Каждый элемент итогового массива -
	Наибольшая длина наибольшего собственного суффикса подстроки, 
	Совпадающего с префиксом

	Сопоставляем первому элементу ноль
*/
vector<int> prefix_function(string s) {
	int n = s.length(); 
	vector<int> pi(n);				  // массив-результат, префикс-функция
	for (int i = 1; i < n; ++i) { 
		int j = pi[i - 1];			  // длина текущего рассматриваемого образца
		while (j > 0 && s[i] != s[j]) // этот цикл предназначен для того чтобы исключить
			j = pi[j - 1];			  // ошибку в строках типа aabaaa
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
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
	
	vector <int> result = prefix_function(strToBePrefixed);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}

	cout << endl;

	system("pause");
	return 0;
}