#include <stdio.h>
#include <omp.h>
#include <iostream>
int main()
{
    int nthreads;
    int tid;
    // �������� ������������ �������
#pragma omp parallel private(tid)
    {
        // ������ ������ ������
        tid = omp_get_thread_num();
        printf("Hello World from thread = %d\n", tid);
        // ������ ���������� ������� � ������ master
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }
    } // ���������� ������������ �������
    system("pause");
    return 0;
}