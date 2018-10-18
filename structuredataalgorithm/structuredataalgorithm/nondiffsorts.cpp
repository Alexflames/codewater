#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
/*
	Сортировка подсчётом - заполняем массив на i-ое место элемент со значением i
	Проходим по новому массиву, если на i-ом месте не 0, уменьшаем
	на 1 и добавляем в массив-результат
*/
#pragma region инициализация исходного массива
	int n;
	cout << "Enter the number of elements in array that is to be sort then the array itself" << endl;
	cin >> n;
	vector <int> input;
	int maxNumberInInput;
	int minNumberInInput;
	for (int i = 0; i < n; i++) 
		int input_number;
		cin >> input_number;
		input.push_back(input_number);
		if (i == 0) {	// Первый элемент возьмём за минимум и максимум
			minNumberInInput = input_number;
			maxNumberInInput = input_number;
		}
		minNumberInInput = min(input_number, minNumberInInput);
		// Сохраняем максимум для определения размерности сортирующего вектора
		maxNumberInInput = max(input_number, maxNumberInInput);  
	}
#pragma endregion	
	// Создание массива, содержащего количество встречаемых чисел 
	// На i-ом месте значение элемента массива равно количеству встретившихся чисел равных i
	// С индексом 0 будет минимальный элемент, с индексом size() - 1 будет максимальный
	vector <int> sortingVector(maxNumberInInput + 1 - minNumberInInput);
	for (int i = 0; i < input.size(); i++) {
		sortingVector[input[i] - minNumberInInput]++;
	}

	// В отсортированном порядке добавляем элементы в массив-результат.
	vector <int> result;
	for (int i = 0; i < sortingVector.size(); i++) {
		for (int j = 0; j < sortingVector[i]; j++) {
			result.push_back(i + minNumberInInput);
			sortingVector[i]--;
		}
	}

	// Вывод результата
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}