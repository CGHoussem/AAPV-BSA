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

public:
    BinarySearch(void* ar, int size, DATA_TYPE dt);
    ~BinarySearch();

    void dump();
};