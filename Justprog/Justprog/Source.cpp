#include <iostream>//���������� �����-������
#include <fstream>//���������� ��� ������/������ �/�� �����
#include <string>//���������� �����
#include <string.h>//���������� ��� ������ �� ��������
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	string s, s1, s2;//���������� ����������
	cout << "������� �����(������), ������� ���� ��������/n";
	cin >> s1;
	s2 = "...";//���������� ����������
	string razdel = "!?,.:;- ";//���������� ����������
	ifstream in("input.txt"); //��� ������
	ofstream out("output.txt"); // ��� ������
	while (in.peek() != EOF) { // ���� �� ������ �� ����� �����
		getline(in, s); //��������� ������ ���� �++
		s += '.';
		string::size_type pos = 0, k;
		k = s.find_first_of(razdel);
		while (k != string::npos) {

			string word = s.substr(pos, k - pos); //����� �����
			int k1 = k;

			if (word.find(s1) != string::npos) {
				s.replace(pos, k - pos, s2); //���� ����� �������� �������� ������, �������� ��� �� ��� �����
				pos += 3;
				if (ispunct(s[pos])) pos += 2; //���� ����� ���� ����������
				else pos += 1;
				k = s.find_first_of(razdel, pos); //���� ����� ���������� �����
			}
			else {
				if (ispunct(s[k])) pos = k + 2; //���� ����� ���� ����������
				else pos = k + 1;
				k = s.find_first_of(razdel, pos); //���� ����� ���������� �����
			}

		}
		out << s << endl;
	}
	in.close();
	out.close();
	system("pause");//�������� �������
	return 0;
}