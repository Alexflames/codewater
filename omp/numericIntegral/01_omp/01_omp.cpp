// 01_omp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <omp.h>

using namespace std;

// Число pi
#define PI 3.1415926535897932384626433832795

double fun(double x) {
    return 1 / sqrt(1 - x * x);
}


double funZnam(double a1, double b1, double a2, double b2) {
    return (b1 - a1) * (b2 - a2);
}

double funI2(double znam, double sumI1, double sumPix, double y) {
    return sumI1 * (exp(sin(sumPix) * cos(PI * y)) + 1) / znam;
}

// Вычисляет степень экспоненты которая связана с x
double funPix(double x) {
    return PI * x;
}

double fun2(double x, double y, double znam) {
    return (exp(sin(PI * x) * cos(PI * y)) + 1) / znam;
}

//void doubleIntegral(const double a1, const double b1,
//    const double a2, const double b2,
//    const double h, double *res)
//{
//    int i, j, n1, n2;
//    double sumI1, sumPix, sum; // локальная переменная для подсчета интеграла
//    double x, y; // координата точки сетки
//    n1 = (int)((b1 - a1) / h); // количество точек сетки интегрирования
//    n2 = (int)((b2 - a2) / h); // количество точек сетки интегрирования
//    sum = sumPix = sumI1 = 0.0;
//#pragma omp parallel for private(x) reduction(+: sumI1, sumPix)
//    for (j = 0; j < n1; j++)
//    {
//        x = a1 + j * h + h / 2.0;
//        sumI1 += funI1(a1, b1, a2, b2) * h;
//        sumPix += funPix(x) * h;
//    }
//#pragma omp parallel for private(y) reduction(+: sum)
//    for (i = 0; i < n2; i++) {
//        y = a2 + i * h + h / 2.0;
//        sum += funI2(sumI1, sumPix, y) * h;
//    }
//    *res = sum;
//}

void doubleIntegral(const double a1, const double b1,
    const double a2, const double b2,
    const double h, double *res)
{
    int i, j, n1, n2;
    double sumI1, sumPix, sum; // локальная переменная для подсчета интеграла
    double x, x2, y, y2; // координата точки сетки
    n1 = (int)((b1 - a1) / h); // количество точек сетки интегрирования
    n2 = (int)((b2 - a2) / h); // количество точек сетки интегрирования
    sum = sumPix = sumI1 = 0.0;
    double znam = funZnam(a1, b1, a2, b2);
#pragma omp parallel for private(x, x2, y, y2) reduction(+: sum)
    for (j = 0; j < n1; j++)
    {
        x = a1 + j * h;
        x2 = x + h;
        //#pragma omp parallel for private(y) reduction(+:sum)
        for (i = 0; i < n2; i++) {
            y = a2 + i * h;
            y2 = y + h;
            double f1 = fun2(x, y, znam) * h * h;
            double f2 = fun2(x2, y2, znam) * h * h;
            sum += (f1 + f2) / 2.0;
        }
    }
//#pragma omp parallel for private(y) reduction(+: sum)
    *res = sum;
}

void integral(const double a, const double b,
    const double h, double *res)
{
    int i, n;
    double sum; // локальная переменная для подсчета интеграла
    double x; // координата точки сетки
    n = (int)((b - a) / h); // количество точек сетки интегрирования
    sum = 0.0;
#pragma omp parallel for private(x) reduction(+: sum)  
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
#pragma omp parallel for reduction(+: sum1)
    for (i = 1; i <= n; i++)
    {
        sum1 += fun(a + (2 * i - 1) * h);
    }
#pragma omp parallel for reduction(+: sum2)  
    for (i = 0; i < n; i++)
    {
        sum2 += fun(a + 2 * i * h);
    }
    *res = (h / 3) * (fun(a) + fun(b) + 4 * sum1 + 2 * sum2) ;
}


double experiment(double *res)
{
    double stime, ftime; // время начала и конца расчета
    double a = 0.0; // левая граница интегрирования
    double b = 0.99999999; // правая граница интегрирования
    double h = 0.0000001; // шаг интегрирования
    stime = clock();
    integralSimpson(a, b, h, res); // вызов функции интегрирования
    //doubleIntegral(0, 16, 0, 16, h, res); // вызов функции интегрирования
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
