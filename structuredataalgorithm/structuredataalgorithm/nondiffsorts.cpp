#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
/*
	���������� ��������� - ��������� ������ �� i-�� ����� ������� �� ��������� i
	�������� �� ������ �������, ���� �� i-�� ����� �� 0, ���������
	�� 1 � ��������� � ������-���������
*/
#pragma region ������������� ��������� �������
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
		if (i == 0) {	// ������ ������� ������ �� ������� � ��������
			minNumberInInput = input_number;
			maxNumberInInput = input_number;
		}
		minNumberInInput = min(input_number, minNumberInInput);
		// ��������� �������� ��� ����������� ����������� ������������ �������
		maxNumberInInput = max(input_number, maxNumberInInput);  
	}
#pragma endregion	
	// �������� �������, ����������� ���������� ����������� ����� 
	// �� i-�� ����� �������� �������� ������� ����� ���������� ������������� ����� ������ i
	// � �������� 0 ����� ����������� �������, � �������� size() - 1 ����� ������������
	vector <int> sortingVector(maxNumberInInput + 1 - minNumberInInput);
	for (int i = 0; i < input.size(); i++) {
		sortingVector[input[i] - minNumberInInput]++;
	}

	// � ��������������� ������� ��������� �������� � ������-���������.
	vector <int> result;
	for (int i = 0; i < sortingVector.size(); i++) {
		for (int j = 0; j < sortingVector[i]; j++) {
			result.push_back(i + minNumberInInput);
			sortingVector[i]--;
		}
	}

	// ����� ����������
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}