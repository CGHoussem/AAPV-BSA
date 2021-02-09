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
    for (size_t i = 0; i < size; i++)
        int_input[i] = rand() % (max_value+1); // [0 .. max_value]
    #pragma endregion IntegerArrayCreation

    #pragma region DoubleArrayCreation
    double* double_input = (double*) malloc(sizeof(double) * size);
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(0, max_value); // [0 .. max_value]
    for (size_t i = 0; i < size; i++)
        double_input[i] = distr(eng);
    #pragma endregion DoubleArrayCreation

    BinarySearch int_bs = BinarySearch(int_input, size, INTEGER);
    int_bs.dump();

    BinarySearch double_bs = BinarySearch(double_input, size, DOUBLE);
    double_bs.dump();

    return EXIT_SUCCESS;
}

bool is_arg_valid(char* input) {
    int length = strlen(input);
    int index = 0;

    while (index < length && std::isdigit(input[index]) != 0)
        index++;

    return index >= length;
}
