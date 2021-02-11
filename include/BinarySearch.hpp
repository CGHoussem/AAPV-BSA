#pragma once

template <typename T>
class BinarySearch
{
private:
    T* ar;
    int size;

    int recursive_search_call(int low, int high, T x);

public:
    BinarySearch(T*, int);
    ~BinarySearch();

    int iterative_search(T x);
    int recursive_search(T x);

    // Prints out to the standard output the array content
    void dump();
};