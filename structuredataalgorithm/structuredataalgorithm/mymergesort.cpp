#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Сортировка слиянием. Были созданы 2 функции, реализующие это

// Функция слияния 2 подмассивов в отсортированный массив
 void merge(vector <int> & a, int left, int mid, int right) {
	int it1 = 0;
	int it2 = 0;
	vector <int> result(right - left + 1);

	while (left + it1 < mid && mid + it2 < right) {
		if (a[left + it1] < a[mid + it2]) {
			result[it1 + it2] = a[left + it1];
			it1 += 1;
		}
		else {
			result[it1 + it2] = a[mid + it2];
			it2 += 1;
		}
	}

	while (left + it1 < mid) {
		result[it1 + it2] = a[left + it1];
		it1 += 1;
	}

	while (mid + it2 < right) {
		result[it1 + it2] = a[mid + it2];
		it2 += 1;
	}

	for (int i = 0; i < it1 + it2; i++)
		a[left + i] = result[i];
}

 // Рекурсивная функция, разделяющая массив на подмассивы, в которых затем вызывается функция слияния
 // При первом запуске left = 0, right = array.size()
 void mergeSortRecursive(vector <int> & a, int left, int right) {
	 if (left + 1 >= right)
		 return;
	 int mid = (left + right + 1) / 2;		// Находим средний элемент
	 mergeSortRecursive(a, left, mid);
	 mergeSortRecursive(a, mid, right);
	 merge(a, left, mid, right);
 }

int main() {
	ofstream out("output.txt");
	time_t thistime = time(NULL);
	srand(time(&thistime));

#pragma region инициализация исходного массива
	int n;
	int switch_num;
	cout << "Enter 1 to input array manually (Default = 0 = auto)" << endl;
	cin >> switch_num;
	vector <int> input;
	cout << "Enter the number of elements in array that is to be sort" << endl;
	cin >> n;
	switch (switch_num)
	{
	case 1:
		cout << "Enter the array" << endl;
		for (int i = 0; i < n; i++) {
			int input_number;
			cin >> input_number;
			input.push_back(input_number);
		}
		break;
	default:
		for (int i = 0; i < n; i++) {
			int input_number = rand() % 5000;
			input.push_back(input_number);
		}
		break;
	}
	
#pragma endregion

	int startAlg = clock();
	mergeSortRecursive(input, 0, input.size());		// запуск рекурсивного алгоритма сортировки слиянием
	int endAlg = clock();
	out << "Time passed since algorithm's start (in m/s): " << endAlg - startAlg << endl;

	// Вывод результата
	for (int i = 0; i < n; i++) {
		out << input[i] << " ";
	}
	system("pause");
	return 0;
}