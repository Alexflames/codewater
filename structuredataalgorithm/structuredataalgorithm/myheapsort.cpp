#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Пирамидальная сортировка. Были созданы 3 функции, реализующие это

// Проверяет всех детей у i-го элемента, проверяя, меньше ли они заданного,
// И исправляя если нет
void sink(vector <int> & a, int i, int max) {
	int big_index, child;
	while (i < max) {
		big_index = i;
		int childleft = 2 * i + 1;
		int childright = childleft + 1;

		if (childleft < max && a[childleft] > a[big_index])
			big_index = childleft;

		if (childright < max && a[childright] > a[big_index])
			big_index = childright;

		if (big_index == i)
			return;

		swap(a[i], a[big_index]);
		i = big_index;
	}
 }

// Идём с середины (дети среднего будут последними элементами) и
// запускаем функцию sink. На нулевом элементе массив станет бинарной кучей
void build_heap(vector <int> & a) {
	int index = a.size() / 2 - 1;

	while (index >= 0) {
		sink(a, index, a.size());
		index--;
	}
}

// Запуск вспомогательных функций
void heapSort(vector <int> & a) {
	build_heap(a);

	int end = a.size() - 1;

	while (end >= 0) {
		swap(a[0], a[end]); // Самый большой элемент (первый в куче) в итоге окажется на последнем месте
		sink(a, 0, end);
		end--;
	}
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
	heapSort(input);		// запуск рекурсивного алгоритма пирамидальной сортировки
	int endAlg = clock();
	out << "Time passed since algorithm's start (in m/s): " << endAlg - startAlg << endl;

	// Вывод результата
	for (int i = 0; i < n; i++) {
		out << input[i] << " ";
	}
	system("pause");
	return 0;
}