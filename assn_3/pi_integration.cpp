#include <omp.h>
#include <iostream>
#include <cstdlib>
#include <string>
int main(int argc, char *argv[])
{
    int num_intervals = 2000000000;
    if (argc == 2)
    {
        num_intervals = std::stoi(argv[1]);
    }
    double res = 0;
    double step_size = 1.0 / num_intervals;
    int num_threads = omp_get_max_threads();
    std::cout << "Using max threads " << num_threads << "\n";
    auto start_time = omp_get_wtime();
#pragma omp parallel for reduction(+ : res)
    for (int i = 0; i < num_intervals; i++)
    {
        double mid_point = step_size / 2 + i * step_size;
        double val = 4.0 / (1 + mid_point * mid_point);
        res = res + step_size * val;
    }
    auto end_time = omp_get_wtime();
    std::cout << "Using " << num_threads << " time taken is " << end_time - start_time << " seconds\n";
    std::cout << "Result is " << res << "\n";
    return 0;
}