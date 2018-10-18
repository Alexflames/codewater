#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Быстрая сортировка. Были созданы 2 вспомогательные функции, реализующие это.

int partition(vector <int> & arr, int l, int r) {
	int middleValue = arr[(l + r) / 2]; // Значение среднего элемента, с которым будет
										// проводиться сравнение
	int i = l;
	int j = r;
	while (i <= j) {
		while (arr[i] < middleValue)	// Слева 
			i++;
		while (arr[j] > middleValue)
			j--;

		// Если прервались первые 2 цикла, то это значит, что либо
		// элемент слева больше среднего или элемент справа меньше среднего,
		// либо i стал больше j (соответственно, ожидается, что элемент с индексом
		// i будет больше j, но тогда не сработает из-за описанного выше условия код ниже)
		if (i <= j) {
			swap(arr[i], arr[j]);   // Замена элементов + увеличение i на 1
			if (i < r)				//					и уменьшение j на 1
				i++;						
			if (j > l)
				j--;
		}
	}
	return j;
}

// Рекурсивная функция быстрой сортировки
void quicksort(vector <int> & arr, int l, int r) {
	if (l < r) {
		int newMiddle = partition(arr, l, r);	// partition возвращает индекс среднего элемента
		quicksort(arr, l, newMiddle);			// слева до середины
		quicksort(arr, newMiddle + 1, r);		// с середины до правого конца массива
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
			int input_number = rand() % 1000;
			input.push_back(input_number);
		}
		break;
	}
	
#pragma endregion
	int startAlg = clock();
	quicksort(input, 0, input.size() - 1);		// запуск рекурсивного алгоритма быстрой сортировки
	int endAlg = clock();
	out << "Time passed since algorithm's start (in m/s): " << endAlg - startAlg << endl;
	// Вывод результата
	for (int i = 0; i < n; i++) {
		out << input[i] << " ";
	}
	system("pause");
	return 0;
}