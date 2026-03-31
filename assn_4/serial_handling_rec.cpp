#define N 10000000
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <omp.h>
int main()
{
    int i;
    int *b = new int[N];
    int *c = new int[N];
    int *d = new int[N];
    for (i = 0; i < N; i++)
        b[i] = c[i] = d[i] = rand();

    double start = omp_get_wtime();
    // parallelize this loop
    for (i = 1; i < N; i++)
    {
        b[i] = 1 + i;
        c[i] = b[i - 1] + i;
        d[i] = c[i - 1] + i;
    }
    double end = omp_get_wtime();

    std::cout << "Time taken: " << end - start << " seconds" << std::endl;
    std::cout << b[N - 1] << std::endl
              << c[N - 1] << std::endl
              << d[N - 1] << std::endl;
}