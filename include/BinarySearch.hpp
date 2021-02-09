#pragma once
#include <iostream>

enum DATA_TYPE {
    INTEGER,
    DOUBLE
};

class BinarySearch
{
private:
    DATA_TYPE dt;
    void* ar;
    int size;
    
    int recursive_search_call_int(int low, int high, int x);
    int recursive_search_call_double(int low, int high, double x);

public:
    BinarySearch(void* ar, int size, DATA_TYPE dt);
    ~BinarySearch();

    int iterative_search_int(int x);
    int iterative_search_double(double x);
    int recursive_search_int(int x);
    int recursive_search_double(double x);

    // Prints out to the standard output the array content
    void dump();
};