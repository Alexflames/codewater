#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
/*
	����������� ����������. ��� ���������� ���������� ��� ������ ���������������
	��������� ������ digitBased, ������ i-�� ������ �������� ����� ��������� �����, 
	������� � ������� ������� ����� i. ����� ������ ����� �������������� � �������� ������. 
	����� �������� �����������.
*/
#pragma region ������������� ��������� �������
	int n;
	cout << "Enter the number of elements in array that is to be sort then the array itself" << endl;
	cin >> n;
	vector <int> input;
	int maxNumberInInput = 0;
	for (int i = 0; i < n; i++) {
		int input_number;
		cin >> input_number;
		input.push_back(input_number);
		maxNumberInInput = max(input_number, maxNumberInInput);
	}
#pragma endregion
	int digitCounter = 0;
	while (maxNumberInInput != 0) {		  // ��������� ������������ ���������� �������� � �����
		maxNumberInInput /= 10;
		digitCounter++;
	}	
	vector <vector <int>> digitBased(10); // �������� ���������� �������. ������� ������� �������� ������������� 
										  // ����� �� 0 �� 9
	int digitMultiplier = 1;
	for (int i = 0; i < digitCounter; i++) {
		for (int j = 0; j < n; j++) {
			int digit = input[j] / digitMultiplier % 10; // ������� ��� ���������� �����
			digitBased[digit].push_back(input[j]);
		}
		input.erase(input.begin(), input.end());		 // ������� ������, �������� ��� �����
		for (int j = 0; j < digitBased.size(); j++) {
			for (int k = 0; k < digitBased[j].size(); k++) {
				input.push_back(digitBased[j][k]);
			}
			digitBased[j].erase(digitBased[j].begin(), digitBased[j].end()); // ������� ����������
		}
		digitMultiplier *= 10; // �������� ������ �� 1
	}

	// ����� ����������
	for (int i = 0; i < n; i++) {
		cout << input[i] << " ";
	}
	system("pause");
	return 0;
}