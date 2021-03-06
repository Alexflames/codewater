// SerialGauss.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <omp.h>

int* pPivotPos; // The number of pivot rows selected at the iterations
int* pPivotIter; // The iterations, at which the rows were pivots

using namespace std;

typedef struct {
	int PivotRow;
	double MaxValue;
} TThreadPivotRow;

// Function for simple initialization of the matrix
// and the vector elements
void DummyDataInitialization(double* pMatrix, double* pVector, int
    Size) {
    int i, j; // Loop variables
    for (i = 0; i < Size; i++) {
        pVector[i] = i + 1;
        for (j = 0; j < Size; j++) {
            if (j <= i)
                pMatrix[i*Size + j] = 1;
            else
                pMatrix[i*Size + j] = 0;
        }
    }
}

// Function for testing the result
void TestResult(double* pMatrix, double* pVector,
    double* pResult, int Size) {
    /* Buffer for storing the vector, that is a result of multiplication
    of the linear system matrix by the vector of unknowns */
    double* pRightPartVector;
    // Flag, that shows wheather the right parts
    // vectors are identical or not
    int equal = 0;
    double Accuracy = 0.5; // Comparison accuracy
    pRightPartVector = new double[Size];
    for (int i = 0; i<Size; i++) {
        pRightPartVector[i] = 0;
        for (int j = 0; j<Size; j++) {
            pRightPartVector[i] +=
                pMatrix[i*Size + j] * pResult[j];
        }
    }
    for (int i = 0; i<Size; i++) {
        if (fabs(pRightPartVector[i] - pVector[i]) > Accuracy)
            equal = 1;
    }
    if (equal == 1)
        printf("The result of the parallel Gauss algorithm is NOT correct."
            "Check your code.");
    else
        printf("The result of the parallel Gauss algorithm is correct.\n");
    delete[] pRightPartVector;
}
// Function for random initialization of the matrix
// and the vector elements
void RandomDataInitialization(double* pMatrix, double* pVector,
    int Size) {
    int i, j; // Loop variables
    srand(unsigned(clock()));
    for (i = 0; i < Size; i++) {
        pVector[i] = rand() / double(1000);
        for (j = 0; j < Size; j++) {
            if (j <= i)
                pMatrix[i*Size + j] = rand() / double(1000);
            else
                pMatrix[i*Size + j] = 0;
        }
    }
}
void Task5Initalization(double* &pMatrix, double* &pVector, double* &pResult) {
	pMatrix = new double[25], pVector = new double[5], pResult = new double[5];
	pMatrix[0] = 5, pMatrix[1] = 2, pMatrix[2] = -7, pMatrix[3] = 14;
	pMatrix[5] = 5, pMatrix[6] = -1, pMatrix[7] = 8, pMatrix[8] = -13, pMatrix[9] = 3;
	pMatrix[10] = 10, pMatrix[11] = 1, pMatrix[12] = -2, pMatrix[13] = 7, pMatrix[14] = -1;
	pMatrix[15] = 15, pMatrix[16] = 3, pMatrix[17] = 15, pMatrix[18] = 9, pMatrix[19] = 7;
	pMatrix[20] = 2, pMatrix[21] = -1, pMatrix[22] = -4, pMatrix[23] = 5, pMatrix[24] = -7;
	pVector[0] = 21, pVector[1] = 12, pVector[2] = 29, pVector[3] = 130, pVector[4] = -13;
}

// Function for memory allocation and definition of the objects elements 
void ProcessInitialization(double* &pMatrix, double* &pVector,
    double* &pResult, int &Size) {
    // Setting the size of the matrix and the vector
    do {
        printf("\nEnter size of the matrix and the vector: ");
        scanf_s("%d", &Size);
        printf("\nChosen size = %d \n", Size);
        if (Size <= 0)
            printf("\nSize of objects must be greater than 0!\n");
    } while (Size <= 0);
    // Memory allocation
    pMatrix = new double[Size*Size];
    pVector = new double[Size];
    pResult = new double[Size];
    // Initialization of the matrix and the vector elements
    DummyDataInitialization(pMatrix, pVector, Size);
    //RandomDataInitialization(pMatrix, pVector, Size);
}
// Function for formatted matrix output
void PrintMatrix(double* pMatrix, int RowCount, int ColCount) {
    int i, j; // Loop variables
    for (i = 0; i < RowCount; i++) {
        for (j = 0; j < ColCount; j++)
            printf("%7.4f ", pMatrix[i*RowCount + j]);
        printf("\n");
    }
}
// Function for formatted vector output
void PrintVector(double* pVector, int Size) {
    int i;
    for (i = 0; i < Size; i++)
        printf("%7.4f ", pVector[i]);
}
// Finding the pivot row
int ParallelFindPivotRow(double* pMatrix, int Size, int Iter) {
	int PivotRow = -1; // The index of the pivot row
	double MaxValue = 0; // The value of the pivot element
	int i; // Loop variable
	// Choose the row, that stores the maximum element
#pragma omp parallel
	{
		TThreadPivotRow ThreadPivotRow;
		ThreadPivotRow.MaxValue = 0;
		ThreadPivotRow.PivotRow = -1;
#pragma omp for
		for (i = 0; i < Size; i++) {
			if ((pPivotIter[i] == -1) &&
				(fabs(pMatrix[i*Size + Iter]) > ThreadPivotRow.MaxValue)) {
				ThreadPivotRow.PivotRow = i;
				ThreadPivotRow.MaxValue = fabs(pMatrix[i*Size + Iter]);
			}
		}
		//printf("\n Local thread (id = %i) pivot row : %i ", omp_get_thread_num(), ThreadPivotRow.PivotRow);
#pragma omp critical
        {
            if (ThreadPivotRow.MaxValue > MaxValue) {
                MaxValue = ThreadPivotRow.MaxValue;
                PivotRow = ThreadPivotRow.PivotRow;
            }
        } // pragma omp critical
    } // pragma omp parallel
    return PivotRow;
}


// Column elimination
void ParallelColumnElimination(double* pMatrix, double* pVector,
    int Pivot, int Iter, int Size) {
    double PivotValue, PivotFactor;
    PivotValue = pMatrix[Pivot*Size + Iter];
#pragma omp parallel for private(PivotFactor) schedule(dynamic,1)
    for (int i = 0; i<Size; i++) {
        if (pPivotIter[i] == -1) {
            PivotFactor = pMatrix[i*Size + Iter] / PivotValue;
            for (int j = Iter; j<Size; j++) {
                pMatrix[i*Size + j] -= PivotFactor * pMatrix[Pivot*Size + j];
            }
            pVector[i] -= PivotFactor * pVector[Pivot];
        }
    }
}

// Gaussian elimination
void ParallelGaussianElimination(double* pMatrix, double* pVector,
    int Size) {
    int Iter; // The number of the iteration of the Gaussian
              // elimination
    int PivotRow; // The number of the current pivot row
    for (Iter = 0; Iter<Size; Iter++) {
        // Finding the pivot row
        PivotRow = ParallelFindPivotRow(pMatrix, Size, Iter);
        pPivotPos[Iter] = PivotRow;
        pPivotIter[PivotRow] = Iter;
        ParallelColumnElimination(pMatrix, pVector, PivotRow, Iter, Size);
    }
}

// Back substation
void ParallelBackSubstitution(double* pMatrix, double* pVector,
    double* pResult, int Size) {
    int RowIndex, Row;
    for (int i = Size - 1; i >= 0; i--) {
        RowIndex = pPivotPos[i];
        pResult[i] = pVector[RowIndex] / pMatrix[Size*RowIndex + i];
#pragma omp parallel for private (Row)
        for (int j = 0; j<i; j++) {
            Row = pPivotPos[j];
            pVector[Row] -= pMatrix[Row*Size + i] * pResult[i];
            pMatrix[Row*Size + i] = 0;
        }
    }
}

// Function for the execution of Gauss algorithm
void ParallelResultCalculation(double* pMatrix, double* pVector,
    double* pResult, int Size) {
    // Memory allocation
    pPivotPos = new int[Size];
    pPivotIter = new int[Size];
    for (int i = 0; i<Size; i++) {
        pPivotIter[i] = -1;
    }
    ParallelGaussianElimination(pMatrix, pVector, Size);
    ParallelBackSubstitution(pMatrix, pVector, pResult, Size);
    // Memory deallocation
    delete[] pPivotPos;
    delete[] pPivotIter;
}

// Function for computational process termination
void ProcessTermination(double* pMatrix, double* pVector, double*
    pResult) {
    delete[] pMatrix;
    delete[] pVector;
    delete[] pResult;
}

void Task6Initalization(double* &X, double Size, double* &xn) {
	X = new double[Size];
	xn = new double[Size];
	for (int i = 0; i < Size; i++) {
		X[i] = i;
	}
}

// Task 6 - Верхняя релаксация
void Task6(double* A, double* B, int n, float eps, double* X, float w, double* xn) {
	float norm = 0;
	for (int i = 0; i < n; i++) {
		xn[i] = 0;
		X[i] = xn[i];
	}
	int i, j;
	do {
#pragma omp for private (i, j)
		for (i = 0; i < n; i++) {
			X[i] = B[i];
			for (j = 0; j < n; j++) {
				if (i != j) {
					X[i] = X[i] - A[i * n + j] * X[j];
				}
			}
			X[i] /= A[i * n + i];

			X[i] = w * X[i] + (1 - w) * xn[i];
			if (X[i] - xn[i] > norm) {
				norm = abs(X[i] - xn[i]);
				xn[i] = X[i];
			}
		}
		norm = 0;
	} while (norm > eps);
}

int main() {
    double* pMatrix; // The matrix of the linear system
    double* pVector; // The right parts of the linear system
    double* pResult; // The result vector
	double* X;
	double* xn;
    int Size; // The size of the matrix and the vectors
    double start, finish, duration;
    // Data initialization
    ProcessInitialization(pMatrix, pVector, pResult, Size);
	//Task5Initalization(pMatrix, pVector, pResult);
	Task6Initalization(X, Size, xn);
    start = omp_get_wtime();
	Task6(pMatrix, pVector, Size, 0.001, X, 1.12, xn);
	//ParallelResultCalculation(pMatrix, pVector, pResult, 5);
    finish = omp_get_wtime();
    duration = finish - start;
    // Testing the result
    TestResult(pMatrix, pVector, X, Size);
	//PrintMatrix(pMatrix, 5, 5);
	//printf("Recalculated vector: \n");
	//PrintVector(X, Size);
    // Printing the time spent by parallel Gauss algorithm
    printf("\n Time of execution: %f\n", duration);
    // Program termination
    ProcessTermination(pMatrix, pVector, pResult);
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
