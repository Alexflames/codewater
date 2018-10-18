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

// Если значение префикс функции на строке = "искомая строка" + "разделитель" + "строка", в которой организован поиск"
// в определенной позиции равен длине "искомой строки", то значит вхождение было найдено, запишем номер символа,
// который является последним в подстроке как если бы не было исходной строки и разделителя.
// Нулевая индексация
vector<int> kmp(string P, string T) {
	int pl = P.length();
	int tl = T.length();
	vector <int> answer;
	vector <int> p = prefix_function(P + "#" + T); // # - разделитель между искомой строкой
		 		                                   // и строкой в которой организован поиск
	for (int i = 0; i < tl; i++) {
		if (p[pl + i + 1] == pl) { // проверяем символ со смещением от исходной строки и разделителя
			answer.push_back(i);
		}
	}
	return answer;
}

int main() {
	setlocale(LC_ALL, "russian");
	time_t thistime = time(NULL);
	srand(time(&thistime));

#pragma region инициализация исходного массива
	int n;
	int switch_num;
	//cout << "Enter 1 to input string manually (Default = 0 = auto)" << endl;
	//cin >> switch_num;
	string strToBePrefixed = "";
	string substring = "";
	/*switch (switch_num)
	{
	case 1:*/
	cout << "Enter the string" << endl;
	cin >> strToBePrefixed;
	cout << "Enter substring" << endl;
	cin >> substring;
	//	break;
	//default:
	//	int strLength;
	//	cout << "enter the length of the string \n";
	//	cin >> strLength;
	//	for (int i = 0; i < strLength; i++) {
	//		char input_char = rand() % 26 + 'a';
	//		strToBePrefixed += input_char;
	//	}
	//	cout << endl << strToBePrefixed << endl;
	//	break;
	//}
	
#pragma endregion

	//int startAlg = clock();	// Начало

	//int endAlg = clock();	// Конец
	//out << "Time passed since algorithm's start (in m/s): " << endAlg - startAlg << endl;
	
	vector <int> result = kmp(substring, strToBePrefixed);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	cout << endl;

	system("pause");
	return 0;
}