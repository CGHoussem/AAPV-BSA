#include "BinarySearch.hpp"

BinarySearch::BinarySearch(void* ar, int size, DATA_TYPE dt)
{
    switch (dt)
    {
    case INTEGER:
        // cast to the appropriate type
        this->ar = (int*) ar;
        break;
    case DOUBLE:
        // cast to the appropriate type
        this->ar = (double*) ar;
        break;
    }

    this->size = size;
    this->dt = dt;
}

BinarySearch::~BinarySearch()
{
    free(this->ar);
}


void BinarySearch::dump() {
    for (size_t i = 0; i < this->size; i++) {
        if (dt == INTEGER)
            std::cout << ((int*)ar)[i] << std::endl;
        else if (dt == DOUBLE)
            std::cout << ((double*)ar)[i] << std::endl;
    }
}