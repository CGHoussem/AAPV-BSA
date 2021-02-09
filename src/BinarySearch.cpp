#include "BinarySearch.hpp"
#include <iomanip>      // std::setprecision
#include <math.h>       // std::fabs

BinarySearch::BinarySearch(void* ar, int size, DATA_TYPE dt)
{
    if (dt == INTEGER)
        this->ar = (int*) ar;
    else if (dt == DOUBLE)
        this->ar = (double*) ar;
    this->size = size;
    this->dt = dt;
}

BinarySearch::~BinarySearch()
{
    free(this->ar);
}

int BinarySearch::iterative_search_int(int x) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x == ((int*)ar)[mid])
            return mid;
        else if (x < ((int*)ar)[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int BinarySearch::iterative_search_double(double x) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x == ((double*)ar)[mid])
            return mid;
        else if (x < ((double*)ar)[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int BinarySearch::recursive_search_call_int(int low, int high, int x) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (x == ((int*)ar)[mid])
        return mid;
    else if (x < ((int*)ar)[mid])
        return recursive_search_call_int(low, mid - 1, x);
    else
        return recursive_search_call_int(mid + 1, high, x);
}

int BinarySearch::recursive_search_call_double(int low, int high, double x) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (std::fabs(x - ((double*)ar)[mid]) < 0.01)
        return mid;
    else if (x < ((double*)ar)[mid])
        return recursive_search_call_double(low, mid - 1, x);
    else
        return recursive_search_call_double(mid + 1, high, x);
}

int BinarySearch::recursive_search_int(int x) {
    return recursive_search_call_int(0, size - 1, x);
}

int BinarySearch::recursive_search_double(double x) {
    return recursive_search_call_double(0, size - 1, x);
}

void BinarySearch::dump() {
    for (size_t i = 0; i < this->size; i++) {
        if (dt == INTEGER)
            std::cout << ((int*)ar)[i] << std::endl;
        else if (dt == DOUBLE)
            std::cout << std::setprecision(10) << ((double*)ar)[i] << std::endl;
    }
}