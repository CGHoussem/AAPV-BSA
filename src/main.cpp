#include <iostream>
#include <random>
#include <string.h>

#include "BinarySearch.hpp"

bool is_arg_valid(char* input);


int main(int argc, char** argv) {
    std::srand(time(nullptr));

    #pragma region ArgumentsValidation
    if (argc <= 2) {
        std::cout << "USAGE: ./AAPV-BSA array_size max_value\n";
        return EXIT_FAILURE;
    }

    if (!is_arg_valid(argv[1])) {
        std::cout << "ERROR: array_size should be a positive integer\n";
        return EXIT_FAILURE;
    }
    int size = std::stoi(argv[1]);
    if (size <= 0) {
        std::cout << "ERROR: array_size should be > 0\n";
        return EXIT_FAILURE;
    }

    if (!is_arg_valid(argv[2])) {
        std::cout << "ERROR: max_value should be a positive integer\n";
        return EXIT_FAILURE;
    }
    int max_value = std::stoi(argv[2]);
    if (max_value <= 0) {
        std::cout << "ERROR: max_value should be > 0\n";
        return EXIT_FAILURE;
    }
    #pragma endregion ArgumentsValidation

    #pragma region IntegerArrayCreation
    int* int_input = (int*) malloc(sizeof(int) * size);
    int_input[0] = rand() % ((max_value+1)/size);
    for (size_t i = 1; i < size; i++) {
        int val = rand() % ((i*(max_value+1))/size);
        while (val < int_input[i-1])
            val = rand() % ((i*(max_value+1))/size);
        int_input[i] = val;
    }
    #pragma endregion IntegerArrayCreation

    #pragma region DoubleArrayCreation
    double* double_input = (double*) malloc(sizeof(double) * size);
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(0, max_value/size);
    double_input[0] = distr(eng);
    for (size_t i = 1; i < size; i++) {
        distr = std::uniform_real_distribution<double>(0, (max_value*i)/size);
        double val = distr(eng);
        while (val < double_input[i-1])
            val = distr(eng);
        double_input[i] = val;
    }
    #pragma endregion DoubleArrayCreation

    BinarySearch<int> int_bs(int_input, size);
    // int_bs.dump();

    std::cout << "Iterative search on " << int_input[0] << ": " << int_bs.iterative_search(int_input[0]) << std::endl;
    std::cout << "Recursive search on " << int_input[3] << ": " << int_bs.recursive_search(int_input[3]) << std::endl;

    BinarySearch<double> double_bs(double_input, size);
    // double_bs.dump();

    std::cout << "Iterative search on " << double_input[0] << ": " << double_bs.iterative_search(double_input[0]) << std::endl;
    std::cout << "Recursive search on " << double_input[3] << ": " << double_bs.recursive_search(double_input[3]) << std::endl;

    return EXIT_SUCCESS;
}

bool is_arg_valid(char* input) {
    int length = strlen(input);
    int index = 0;

    while (index < length && std::isdigit(input[index]) != 0)
        index++;

    return index >= length;
}
