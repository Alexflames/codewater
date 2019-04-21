// SerialFFT.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iomanip>
#include <iostream>
#include <cmath>
#include <complex>
#include <time.h>
#include <omp.h>
using namespace std;

#define PI (3.14159265358979323846)

void BitReversing(complex<double> *inputSignal,
	complex<double> *outputSignal, int size) {
	int bitsCount = 0;
	//bitsCount = log2(size)
	for (int tmp_size = size; tmp_size > 1; tmp_size /= 2, bitsCount++);
	//ind - index in input array
	//revInd - correspondent to ind index in output array
	int ind;
//#pragma omp parallel for
	for (ind = 0; ind < size; ind++)
	{
		int mask = 1 << (bitsCount - 1);
		int revInd = 0;
		for (int i = 0; i < bitsCount; i++) //bit-reversing
		{
			bool val = ind & mask;
			revInd |= val << i;
			mask = mask >> 1;
		}
		outputSignal[revInd] = inputSignal[ind];
	}
}

//void BitReversing(complex<double> *inputSignal,
//    complex<double> *outputSignal, int size) {
//    int j = 0, i = 0;
//#pragma omp parallel for reduction(+: j)
//    for (i = 0; i < size; i++)
//    {
//        if (j > i)
//        {
//            outputSignal[i] = inputSignal[j];
//            outputSignal[j] = inputSignal[i];
//        }
//        else
//            if (j == i)
//                outputSignal[i] = inputSignal[i];
//        int m = size >> 1;
//        while ((m >= 1) && (j >= m))
//        {
//            j += -m;
//            m = m >> 1;
//        }
//        j += m;
//    }
//}

__inline void Butterfly(complex<double> *signal,
	complex<double> u, int offset, int butterflySize) {
	complex<double> tem = signal[offset + butterflySize] * u;
	signal[offset + butterflySize] = signal[offset] - tem;
	signal[offset] += tem;
}

void ParallelFFTCalculation(complex<double> *signal, int size) {
	int m = 0;
	int p, i;
	for (int tmp_size = size; tmp_size > 1; tmp_size /= 2, m++);
	for (p = 0; p < m; p++)
	{
		int butterflyOffset = 1 << (p + 1);
		int butterflySize = butterflyOffset >> 1;
		double coeff = PI / butterflySize;
#pragma omp parallel for schedule(static)
		for (i = 0; i < size / butterflyOffset; i++)
			for (int j = 0; j < butterflySize; j++)
				Butterfly(signal, complex<double>(cos(-j * coeff),
					sin(-j * coeff)), j + i * butterflyOffset, butterflySize);
	}
}
// FFT computation
void ParallelFFT(complex<double> *inputSignal,
	complex<double> *outputSignal, int size) {
	BitReversing(inputSignal, outputSignal, size);
	ParallelFFTCalculation(outputSignal, size);
}
void PrintSignal(complex<double> *signal, int size) {
	cout << "Result signal" << endl;
	for (int i = 0; i < size; i++)
		cout << signal[i] << endl;
}

#define PI (3.14159265358979323846)
//Function for simple initialization of input signal elements
void DummyDataInitialization(complex<double>* mas, int size) {
	for (int i = 0; i < size; i++)
		mas[i] = 0;
	mas[size - size / 4] = 1;
}
//Function for memory allocation and data initialization
void ProcessInitialization(complex<double>* &inputSignal,
	complex<double>* &outputSignal, int &size) {
	// Setting the size of signals
	do
	{
		cout << "Enter the input signal length: ";
		cin >> size;
		if (size < 4)
			cout << "Input signal length should be >= 4" << endl;
		else
		{
			int tmpSize = size;
			while (tmpSize != 1)
			{
				if (tmpSize % 2 != 0)
				{
					cout << "Input signal length should be powers of two" << endl;
					size = -1;
					break;
				}
				tmpSize /= 2;
			}
		}
	} while (size < 4);
	cout << "Input signal length = " << size << endl;
	inputSignal = new complex<double>[size];
	outputSignal = new complex<double>[size];
	//Initialization of input signal elements - tests
	DummyDataInitialization(inputSignal, size);
	//Computational experiments
	//RandomDataInitialization(inputSignal, size);
}
//Function for computational process temination
void ProcessTermination(complex<double>* &inputSignal,
	complex<double>* &outputSignal) {
	delete[] inputSignal;
	inputSignal = NULL;
	delete[] outputSignal;
	outputSignal = NULL;
}

// Function for random initialization of objects' elements
void RandomDataInitialization(complex<double>* mas, int size)
{
	srand(unsigned(clock()));
	for (int i = 0; i < size; i++)
		mas[i] = complex<double>(rand() / 1000.0, rand() / 1000.0);
}

// S E R I A L      S E R I A L      
void SerialFFTCalculation(complex<double> *signal, int size) {
	int m = 0;
	for (int tmp_size = size; tmp_size > 1; tmp_size /= 2, m++);
	for (int p = 0; p < m; p++)
	{
		int butterflyOffset = 1 << (p + 1);
		int butterflySize = butterflyOffset >> 1;
		double coeff = PI / butterflySize;
		for (int i = 0; i < size / butterflyOffset; i++)
			for (int j = 0; j < butterflySize; j++)
				Butterfly(signal, complex<double>(cos(-j * coeff),
					sin(-j * coeff)), j + i * butterflyOffset, butterflySize);
	}
}

// S E R I A L      FFT computation
void SerialFFT(complex<double> *inputSignal,
	complex<double> *outputSignal, int size) {
	BitReversing(inputSignal, outputSignal, size);
	SerialFFTCalculation(outputSignal, size);
}

void TestResult(complex<double> *inputSignal,
	complex<double> *outputSignal, int size)
{
	// Buffer for storing the result of serial FFT
	complex<double> *testSerialSignal;
	double Accuracy = 1.e-6; // Comparison accuracy
	// Flag, that shows whether the vectors are identical
	int equal = 0;
	int i; // Loop variable
	testSerialSignal = new complex<double>[size];
	SerialFFT(inputSignal, testSerialSignal, size);
	for (i = 0; i < size; i++)
	{
		if (abs(outputSignal[i] - testSerialSignal[i]) >= Accuracy)
			equal = 1;
	}
	if (equal == 1)
		printf("The results of serial and parallel algorithms are NOT identical.Check your code.");
	else
		printf("The results of serial and parallel algorithms are identical.");
	delete[] testSerialSignal;
}

double sumAn(double t, double T) {
	double eps = 2e-8;
	double sumIter = 1;
	double k = 1;

	double res = 0;
	while (fabs(sumIter) > eps) {
		sumIter = cos(k * 2 * PI / T * t) / k;
		res += sumIter;
		k++;
	}
	return res;
}

double fun(complex<double>* outputSignal, int size, double t, double T) {
	double f = outputSignal[0].real() / 2;
	for (int i = 1; i < size / 2; i++) {
		f += outputSignal[i].real() * cos(i * 2 * PI * t / T) + outputSignal[i].imag() * sin(i * 2 * PI * t / T);
	}
	return f;
}

// ���������� �����������
void Task9(complex<double>* inputSignal, complex<double>* outputSignal, int size, int T) {
	inputSignal		= new complex<double>[size];
	outputSignal	= new complex<double>[size];
	// �� 0 ��� 1?
	for (int i = 1; i < size; i++) {
		double t = i * 1.0 / size;
		inputSignal[i] = complex<double>(-log(2 * sin(PI / T * t)), 0);
	}

	ParallelFFT(inputSignal, outputSignal, size);
	for (int i = 0; i < size; i++) {
		outputSignal[i] /= size / 2.;
	}

	for (int i = 0; i < 64; i++) {
		double t = i / double(size);
		cout << fun(outputSignal, size, t, T) << " --- " 
			 << sumAn(t, T) << " --- " << -log(2.0 * sin(PI * t / T)) << endl;
	}


}

int main()
{
	complex<double> *inputSignal = NULL;
	complex<double> *outputSignal = NULL;
	int size = 1024;
	double T = 1;

	Task9(inputSignal, outputSignal, size, T);
	/*
	int size = 0;
	const int repeatCount = 16;
	double startTime;
	double duration;
	double minDuration = DBL_MAX;
	cout << "Fast Fourier Transform" << endl;
	// Memory allocation and data initialization
	ProcessInitialization(inputSignal, outputSignal, size);

	for (int i = 0; i < repeatCount; i++)
	{
		startTime = clock();
		// FFT computation
		ParallelFFT(inputSignal, outputSignal, size);
		duration = (clock() - startTime) / CLOCKS_PER_SEC;
		if (duration < minDuration)
			minDuration = duration;
	}
	
	TestResult(inputSignal, outputSignal, size);
	cout << setprecision(6);
	cout << "\nExecution time is " << minDuration << " s. " << endl;
	*/
	// Result signal output
	//PrintSignal(outputSignal, size);
	// Computational process termination
	ProcessTermination(inputSignal, outputSignal);
	system("pause");
	return 0;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
