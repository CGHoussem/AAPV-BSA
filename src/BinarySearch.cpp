#include "BinarySearch.hpp"
#include <iostream>
#include <iomanip>      // std::setprecision
#include <math.h>       // std::fabs


template <typename T>
BinarySearch<T>::BinarySearch(T* ar, int size)
{
    this->ar = ar;
    this->size = size;
}

template <typename T>
BinarySearch<T>::~BinarySearch()
{
    free(this->ar);
}

template <typename T>
int BinarySearch<T>::iterative_search(T x) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x == ar[mid])
            return mid;
        else if (x < ar[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

template <typename T>
int BinarySearch<T>::recursive_search_call(int low, int high, T x) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (std::fabs(x - ar[mid]) < 0.01)
        return mid;
    else if (x < ar[mid])
        return recursive_search_call(low, mid - 1, x);
    else
        return recursive_search_call(mid + 1, high, x);
}

template <typename T>
int BinarySearch<T>::recursive_search(T x) {
    return recursive_search_call(0, size - 1, x);
}

template <typename T>
void BinarySearch<T>::dump() {
    for (size_t i = 0; i < this->size; i++) {
        std::cout << std::setprecision(10) << ar[i] << std::endl;
    }
}

template class BinarySearch<int>;
template class BinarySearch<double>;
