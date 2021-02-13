#include <iostream>
#include <random>
#include <string.h>
#include <chrono>
#include <float.h>

#include "BinarySearch.hpp"

bool is_arg_valid(char* input);
int compare_int(const void * a, const void * b);
int compare_double(const void * a, const void * b);


int main(int argc, char** argv) {
    std::srand(time(nullptr));

    #pragma region ArgumentsValidation
    if (argc <= 1) {
        std::cout << "USAGE: ./AAPV-BSA iterations\n";
        return EXIT_FAILURE;
    }

    if (!is_arg_valid(argv[1])) {
        std::cout << "ERROR: iterations should be a positive integer\n";
        return EXIT_FAILURE;
    }
    int iterations = std::stoi(argv[1]);
    if (iterations <= 0) {
        std::cout << "ERROR: iterations should be > 0\n";
        return EXIT_FAILURE;
    }
    #pragma endregion ArgumentsValidation

    // BENCHMARKING
    for (size_t i = 0; i < iterations; i++) {
        int size = std::pow(2, 19+i);
        int si = ((float)size/1024/1024)*sizeof(int);
        int sd = ((float)size/1024/1024)*sizeof(double);
        std::cout << "Integers: " << size*sizeof(int) << " Bytes (" << si << " MBytes)\n";
        std::cout << "Doubles: " << size*sizeof(double) << " Bytes (" << sd << " MBytes)\n";

        std::cout << "Total: " << size*sizeof(int)*sizeof(double) << " Bytes (" << si+sd << " MBytes)\n";

        // fill arrays
        int* int_input = (int*) malloc(sizeof(int) * size);
        double* double_input = (double*) malloc(sizeof(double) * size);
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<double> distr(0, DBL_MAX);
        for (size_t i = 0; i < size; i++) {
            int_input[i] = rand();
            double_input[i] = distr(eng);
        }

        // sort arrays using quick sort algorithm
        qsort(int_input, size, sizeof(int), compare_int);
        qsort(double_input, size, sizeof(double), compare_double);

        // make BinarySearch objects
        BinarySearch<int> int_bs(int_input, size);
        BinarySearch<double> double_bs(double_input, size);

        // test iterative search on 3 values for array 1
        double sum = 0;
        for (size_t j = 0; j < 3; j++) {
            auto start = std::chrono::steady_clock::now();
            int_bs.iterative_search(rand());
            auto end = std::chrono::steady_clock::now();
            auto diff = end - start;
            double diff_milli = std::chrono::duration<double, std::milli> (diff).count();
            sum += diff_milli;
        }
        std::cout << "iterative median (int): " << sum / 3  << std::endl;
        // test recursive search on 3 values for array 1
        sum = 0;
        for (size_t j = 0; j < 3; j++) {
            auto start = std::chrono::steady_clock::now();
            int_bs.recursive_search(rand());
            auto end = std::chrono::steady_clock::now();
            auto diff = end - start;
            double diff_milli = std::chrono::duration<double, std::milli> (diff).count();
            sum += diff_milli;
        }
        std::cout << "recursive median (int): " << sum / 3  << std::endl;
        // test iterative search on 3 values for array 2
        sum = 0;
        for (size_t j = 0; j < 3; j++) {
            auto start = std::chrono::steady_clock::now();
            double_bs.iterative_search(rand());
            auto end = std::chrono::steady_clock::now();
            auto diff = end - start;
            double diff_milli = std::chrono::duration<double, std::milli> (diff).count();
            sum += diff_milli;
        }
        std::cout << "iterative median (double): " << sum / 3  << std::endl;
        // test recursive search on 3 values for array 2
            sum = 0;
        for (size_t j = 0; j < 3; j++) {
            auto start = std::chrono::steady_clock::now();
            double_bs.recursive_search(rand());
            auto end = std::chrono::steady_clock::now();
            auto diff = end - start;
            double diff_milli = std::chrono::duration<double, std::milli> (diff).count();
            sum += diff_milli;
        }
        std::cout << "recursive median (double): " << sum / 3  << "\n---\n";
    }

    return EXIT_SUCCESS;
}

bool is_arg_valid(char* input) {
    int length = strlen(input);
    int index = 0;

    while (index < length && std::isdigit(input[index]) != 0)
        index++;

    return index >= length;
}

int compare_int(const void * a, const void * b) {
    return (*(int*) a - *(int*) b);
}

int compare_double(const void * a, const void * b) {
    return (*(double*) a - *(double*) b);
}
