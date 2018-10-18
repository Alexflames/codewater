#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int v = 1; // Номер варианта

const int start_X = -50;
const int end_X = 50;

struct funValue {
	double x;
	double f;
};

vector <funValue>* CalcSinPartSums(int start, int end, int step) {
	vector <funValue> ans;

	for (int x = start_X; x <= end_X; x += 5) {
		int sign = 1;
		int factNext = 1;
		double factDenominator = 1;
		double chisl_start = 2 * x;
		double chisl = chisl_start;
		double partSum = 2 * x;

		double prevSum = 0;
		int nslags = 0;
		double diff;

		cout << "x = " << x << endl;

		while (nslags == 0 || abs(diff) > 10e-9) {
			prevSum = partSum;

			nslags++;
			// Вычисляем факториал в знаменателе
			factNext++;
			factDenominator *= factNext;
			factNext++;
			factDenominator *= factNext;
			// Вычисляем числитель
			chisl *= chisl_start;
			chisl *= chisl_start;
			// Вычисляем частичную сумму
			sign *= -1;
			partSum += sign * (chisl / factDenominator);

			diff = partSum - prevSum;
		}

		funValue thisStep; thisStep.x = x; thisStep.f = partSum;
		ans.push_back(thisStep);
	}
	return (&ans);
}

// Вынести  вычисления множителей отдельно
vector <funValue>* CalcLangranj(vector <funValue> * inputVector) {
	vector <funValue> result_middleInter;
	vector <funValue> input = *inputVector;

	// инициализация двумерного вектора - знаментали
	vector <vector <double> > denom_val;
	for (int i = 0; i < input.size(); i++)
	{
		vector <double> temp(input.size());
		denom_val.push_back(temp);
	}

	// подсчитываем все возможные скобки знаменателя
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input.size(); j++) {
			if (i == j) continue;
			denom_val[i][j] = input[i].x - input[j].x;
		}
	}

	// цикл по всем значениям желаемым 'x'
	for (int i = 0; i < input.size() - 1; i++)
	{
		// точка, которую собираемся вычислить
		funValue newPoint;
		newPoint.x = (input[i + 1].x + input[i].x) / 2;
		newPoint.f = 0;

		// подсчитываем всевозможные скобки числителя
		vector <double> num_val;
		for (int j = 0; j < input.size(); j++)
		{
			double temp = newPoint.x - input[j].x;
			num_val.push_back(temp);
		}

		// Суммируем слагаемые, из которых составляются интерполируемые точки
		for (int j = 0; j < input.size(); j++)
		{
			double num = 1;
			double denom = 1;
			for (int k = 0; k < input.size(); k++)
			{
				if (j == k) continue;
				num *= num_val[k];
				denom *= denom_val[j][k];
			}
			newPoint.f += input[j].f * num / denom;
		}
		result_middleInter.push_back(input[i]);
		result_middleInter.push_back(newPoint);
	}
	result_middleInter.push_back(input[input.size() - 1]);

	return (&result_middleInter);
}

// Вынести  вычисления множителей отдельно 
vector <funValue> CalcNewton(vector <funValue> * inputVector) {
	vector <funValue> result_middleInter;
	vector <funValue> input = *inputVector;

	// инициализация массива разделенных разностей
	vector <vector <double>> divDiff;

	for (int i = 0; i < input.size(); i++) {
		vector <double> temp;
		divDiff.push_back(temp);
	}

	// разделенные разности нулевого порядка
	for (int i = 0; i < input.size(); i++) {
		divDiff[0].push_back(input[i].f);
	}

	// разделенные разности других порядков
	for (int i = 1; i < input.size(); i++) {
		for (int j = 0; j < input.size() - i; j++) {
			double calcThisDiv = (divDiff[i - 1][j + 1] - divDiff[i - 1][j]) / (input[j + i].x - input[j].x);
			divDiff[i].push_back(calcThisDiv);
		}
	}

	// Нахождение значение функции в срединных точках
	for (int i = 0; i < input.size() - 1; i++) {
		funValue newPoint; newPoint.x = (input[i + 1].x + input[i].x) / 2;

		// нахождение множителей вида (x - x0), (x - x1), ...
		vector <double> xdifx;
		xdifx.push_back(newPoint.x - input[0].x);

		for (int j = 1; j < input.size() - 1; j++) {
			xdifx.push_back(xdifx[j - 1] * (newPoint.x - input[j].x));
		}

		// подсчет значения функции в данной неузловой точке
		newPoint.f = 0;
		newPoint.f += divDiff[0][0];
		for (int j = 1; j < input.size(); j++) {
			newPoint.f += divDiff[j][0] * xdifx[j - 1];
		}
		result_middleInter.push_back(newPoint);
	}
	
	return result_middleInter;
}

vector <vector <double>>* MakeSplineTable4Gauss(vector <funValue> * inputVector) {
	vector <funValue> input = *inputVector;
	// Инициализация массива-результата
	vector <vector <double>> ans;
	for (int i = 0; i < (input.size() - 1) * 4; i++) {
		vector <double> temp;
		ans.push_back(temp);
	}

	// TODO сделать вычисления

	return (&ans);
}

vector <double> Gauss(vector <vector <double>> * inputVector) {
	//vector <double> 
	//vector <double> freeColumn;
	//for (int row = 0; i < inputVector->size())
}

int main() {
	//vector <funValue> part_sums = (*CalcSinPartSums(-3, 3, 2));

	// все 'x' и 'f' из дано ТУТ
	vector <funValue> power3;
	funValue temp = { 1, 1 };
	power3.push_back(temp);
	temp = { 2, 8 };
	power3.push_back(temp);
	temp = { 3, 27 };
	power3.push_back(temp);
	temp = { 4, 64 };
	power3.push_back(temp);
	// в блокноте подсказки
	vector <funValue> result_middleInter = CalcNewton(&power3);



	for (int i = 0; i < result_middleInter.size(); i++) {
		cout << "|  " << result_middleInter[i].x << "  ";
	}
	cout << endl;
	for (int i = 0; i < result_middleInter.size() * 8; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < result_middleInter.size(); i++) {
		cout << "| " << result_middleInter[i].f << " ";
	}

	cout << endl;

	system("pause");
	return 0;
}