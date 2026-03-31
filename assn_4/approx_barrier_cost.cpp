/*
Compilation
Use
g++ -fopenmp -DADD_NOWAIT approx_barrier_cost.cpp -o no_barrier.out
g++ -fopenmp approx_barrier_cost.cpp -o with_barrier.out
*/

#define N 20000
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <omp.h>

int main()
{
    int n = N;
    double *res = new double[n];
    for (int i = 0; i < n; i++)
        res[i] = 0;
    double **matrix = new double *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }

    double *vector = new double[n];

    for (int i = 0; i < n; i++)
    {
        vector[i] = (double)rand() / RAND_MAX;
    }

    double start = omp_get_wtime();
#pragma omp parallel
    {
        for (int col = 0; col < N; col++)
        {
#ifdef ADD_NOWAIT
#pragma omp for schedule(static) nowait
#else
#pragma omp for schedule(static)
#endif
            for (int row = 0; row < N; row++)
            {
                res[row] += matrix[row][col] * vector[row];
            }
        }
    }

    double end = omp_get_wtime();
    std::cout << "Parallel region time: " << end - start << " seconds" << std::endl;

    // Print a value so the compiler cannot optimize away the calculation
    std::cout << "Result sample: " << res[N / 2] << std::endl;
}