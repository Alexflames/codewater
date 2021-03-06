// 01_seq.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

// Число pi
#define PI 3.1415926535897932384626433832795

double fun(double x) {
    return 1 / sqrt(1 - x * x);
}

void integral(const double a, const double b,
    const double h, double *res)
{
    int i, n;
    double sum; // локальная переменная для подсчета интеграла
    double x; // координата точки сетки
    n = (int)((b - a) / h); // количество точек сетки интегрирования
    sum = 0.0;
    for (i = 0; i < n; i++)
    {
        x = a + i * h + h / 2.0;
        sum += fun(x) * h;
    }
    *res = sum;
}

void integralSimpson(const double a, const double b,
    const double h, double *res)
{
    int i, n;
    double sum1, sum2; // локальная переменная для подсчета интеграла
    double x; // координата точки сетки
    n = (int)((b - a) / (h * 2)); // количество точек сетки интегрирования
    sum1 = sum2 = 0.0;
    for (i = 0; i < n; i++)
    {
        sum1 += fun(a + (2 * i - 1) * h);
    }
    for (i = 0; i < n - 1; i++)
    {
        sum2 += fun(a + 2 * i * h);
    }
    *res = (h / 3) * (fun(a) + fun(b) + 4 * sum1 + 2 * sum2);
}


double experiment(double *res)
{
    double stime, ftime; // время начала и конца расчета
    double a = 0.0; // левая граница интегрирования
    double b = 0.99999999; // правая граница интегрирования
    double h = 0.0000001; // шаг интегрирования
    stime = clock();
    integral(a, b, h, res); // вызов функции интегрирования
    ftime = clock();
    return (ftime - stime) / CLOCKS_PER_SEC;
}

int main()
{
    int i; // переменная цикла
    double time; // время проведенного эксперимента
    double res; // значение вычисленного интеграла
    double min_time; // минимальное время работы
    // реализации алгоритма
    double max_time; // максимальное время работы
    // реализации алгоритма
    double avg_time; // среднее время работы
    // реализации алгоритма
    int numbExp = 10; // количество запусков программы
    // первый запуск
    min_time = max_time = avg_time = experiment(&res);
    // оставшиеся запуски
    for (i = 0; i < numbExp - 1; i++)
    {
        time = experiment(&res);
        avg_time += time;
        if (max_time < time) max_time = time;
        if (min_time > time) min_time = time;
    }
    // вывод результатов эксперимента
    cout << "execution time : " << avg_time / numbExp << "; " <<
        min_time << "; " << max_time << endl;
    cout.precision(8);
    cout << "integral value : " << res << endl;
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
