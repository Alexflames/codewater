#include <iostream>//библиотека ввода-вывода
#include <fstream>//библиотека для записи/чтения в/из файла
#include <string>//библиотека строк
#include <string.h>//библиотека для работы со строками
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	string s, s1, s2;//объявление переменных
	cout << "Введите букву(строку), которую надо заменить/n";
	cin >> s1;
	s2 = "...";//объявление переменных
	string razdel = "!?,.:;- ";//объявление переменных
	ifstream in("input.txt"); //для чтения
	ofstream out("output.txt"); // для записи
	while (in.peek() != EOF) { // пока не дойдем до конца файла
		getline(in, s); //считываем строку типа с++
		s += '.';
		string::size_type pos = 0, k;
		k = s.find_first_of(razdel);
		while (k != string::npos) {

			string word = s.substr(pos, k - pos); //копия слова
			int k1 = k;

			if (word.find(s1) != string::npos) {
				s.replace(pos, k - pos, s2); //если слово содержит задданый символ, заменить его на три точки
				pos += 3;
				if (ispunct(s[pos])) pos += 2; //если нашли знак препинания
				else pos += 1;
				k = s.find_first_of(razdel, pos); //ищем конец следующего слова
			}
			else {
				if (ispunct(s[k])) pos = k + 2; //если нашли знак препинания
				else pos = k + 1;
				k = s.find_first_of(razdel, pos); //ищем конец следующего слова
			}

		}
		out << s << endl;
	}
	in.close();
	out.close();
	system("pause");//задержка консоли
	return 0;
}