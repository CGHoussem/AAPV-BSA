#pragma once

template <typename T>
class BinarySearch
{
private:
    T* ar;
    int size;

    int recursive_search_call(int low, int high, T const& x);

public:
    BinarySearch(T* const&, int);
    ~BinarySearch();

    int iterative_search(T const& x);
    int recursive_search(T const& x);

    // Prints out to the standard output the array content
    void dump();
};