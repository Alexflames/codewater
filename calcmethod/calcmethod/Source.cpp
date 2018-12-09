#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

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

//pair<vector <double>, vector<int>> Gauss(vector <vector <double>> * inputVector) {
//	vector <vector <double>> input = *(inputVector);
//	vector <double> minusRow{ 0 };
//	vector <int> xswitch;
//	vector <double> freeCol{ 1 };
//
//	for (int i = 0; i < input.size(); i++) {
//		xswitch.push_back(i);
//	}
//	for (int row = 0; row < input.size(); row++) {
//		// Вычитаем из строки соответственно накопленным преобразованиям
//		for (int col = 0; col < input.size; col++) {
//			input[row][col] -= minusRow[col];
//		}
//
//		// Множитель, на который будет делиться строка
//		double multiplierDel = input[row][row];
//		if (multiplierDel == 0) {
//			int saveRow = 0;
//			for (int rowDesc = row + 1; rowDesc < input.size(); rowDesc++) {
//				if (input[rowDesc][row] != 0) {
//					saveRow = rowDesc;
//					break;
//				}
//			}
//
//			for (int col = row; col < input.size(); col++) {
//				swap(input[row][col], input[saveRow][col]);
//			}
//			swap(freeCol[row], freeCol[saveRow]);
//			multiplierDel = input[row][row];
//		}
//
//		// После данного цикла на диагонали в текущем ряду единица
//		double multiplierDel = input[row][0];
//		for (int col = row; col < input.size(); col++) {
//			input[row][col] /= multiplierDel;
//		}
//		freeCol[row] /= multiplierDel;
//
//		// Надо увеличить 
//		for (int col = row + 1; col < input.size(); col++) {
//			
//		}
//	}
//
//	vector <double> ans;
//	for (int i = 0; i < ans.size; i++) {
//
//	}
//}

void sysout(double **a, double *y, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "*x" << j;
			if (j < n - 1)
				cout << " + ";
		}
		cout << " = " << y[i] << endl;
	}
	return;
}

double * gauss(double **a, double *y, int n)
{
	double *x, max;
	int k, index;
	const double eps = 0.00001;  // точность
	x = new double[n];
	k = 0;
	while (k < n)
	{
		// Поиск строки с максимальным a[i][k]
		max = abs(a[k][k]);
		index = k;
		for (int i = k + 1; i < n; i++)
		{
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				index = i;
			}
		}
		// Перестановка строк
		if (max < eps)
		{
			// нет ненулевых диагональных элементов
			cout << "Решение получить невозможно из-за нулевого столбца ";
			cout << index << " матрицы A" << endl;
			return 0;
		}
		for (int j = 0; j < n; j++)
		{
			double temp = a[k][j];
			a[k][j] = a[index][j];
			a[index][j] = temp;
		}
		double temp = y[k];
		y[k] = y[index];
		y[index] = temp;
		// Нормализация уравнений
		for (int i = k; i < n; i++)
		{
			double temp = a[i][k];
			if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] / temp;
			y[i] = y[i] / temp;
			if (i == k)  continue; // уравнение не вычитать само из себя
			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] - a[k][j];
			y[i] = y[i] - y[k];
		}
		k++;
	}
	// обратная подстановка
	for (k = n - 1; k >= 0; k--)
	{
		x[k] = y[k];
		for (int i = 0; i < k; i++)
			y[i] = y[i] - a[i][k] * x[k];
	}
	return x;
}

void startInterpolation() {
    //vector <funValue> part_sums = (*CalcSinPartSums(-3, 3, 2));

    // все 'x' и 'f' из дано ТУТ
    //vector <funValue> power3;
    //funValue temp = { 1, 1 };
    //power3.push_back(temp);
    //temp = { 2, 8 };
    //power3.push_back(temp);
    //temp = { 3, 27 };
    //power3.push_back(temp);
    //temp = { 4, 64 };
    //power3.push_back(temp);

    //vector <funValue> result_middleInter = CalcNewton(&power3);

    //for (int i = 0; i < result_middleInter.size(); i++) {
    //	cout << "|  " << result_middleInter[i].x << "  ";
    //}
    //cout << endl;
    //for (int i = 0; i < result_middleInter.size() * 8; i++) {
    //	cout << "-";
    //}
    //cout << endl;
    //for (int i = 0; i < result_middleInter.size(); i++) {
    //	cout << "| " << result_middleInter[i].f << " ";
    //}

    //cout << endl;
}

void startGauss() {
    double **a, *y, *x;
    int n;
    system("chcp 1251");
    system("cls");
    cout << "Введите количество уравнений: ";
    cin >> n;
    a = new double*[n];
    y = new double[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "y[" << i << "]= ";
        cin >> y[i];
    }
    sysout(a, y, n);
    x = gauss(a, y, n);
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "]=" << x[i] << endl;
    cin.get(); cin.get();
}

// Функция задана вручную
void methodCoushi(double from, double to, double step, int V) {
    int n = (int)((to - from) / step);
    // Значения x
    double * x = new double[n];
    double * yt = new double[n];
    double * ym = new double[n];
    double * e = new double[n];
    for (int i = 0; from < to + step / 2; from += step) {
        x[i] = from;
        yt[i] = V * x[i] * x[i] * x[i] + V * x[i] + V;
        ym[i] = V + step * (3 * V * x[i] * x[i] + V - V * x[i] * x[i] * x[i] - V - V * x[i]);
        e[i] = abs(yt[i] - ym[i]);
        i++;
    }

    cout.setf(ios::fixed);

    cout << "x = ";
    for (int i = 0; i < n; i++) {
        cout << setw(9) << setprecision(2) << i;
    }
    cout << endl << "y_t ";
    for (int i = 0; i < n; i++) {
        cout << setw(9) << setprecision(2) << yt[i];
    }
    cout << endl << "y_m ";
    for (int i = 0; i < n; i++) {
        cout << setw(9) << setprecision(2) << ym[i];
    }

    cout << endl << "e:  ";
    for (int i = 0; i < n; i++) {
        cout << setw(9) << setprecision(2) << e[i];
    }
}

// Двумя методами надо
void KrayDiff(double from, double to, double step) {
    int n = (int)((to - from) / step);

    double ** table = new double*[n] {new double[n]};
    double * ans = new double[n];

    double x = from;
    double h = step;
    for (int i = 0; x < to + (step / 2); i++, x += step) {
        double a, b, c;
        a = i == 0 ? 0 : 1 / (h * h) - (x * x / (2 * h));
        b = x * x * x - (2 / (h * h));   // не наоборот ли?
        c = i == n - 1 ? 0 : 1 / (h * h) + (x * x) / (2 * h);
        
        if (i != 0) table[i][i - 1] = a;
        table[i][i] = b;
        if (i != n) table[i][i + 1] = c;
        if (i == 0) ans[i] = 0;

    }
}

int main() {
    // methodCoushi(1, 11, 1, 1);
    KrayDiff(1, 11, 1);
	system("pause");
	return 0;
}