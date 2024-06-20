#include "pch.h"
#include "framework.hpp"

#include "Basics/Sort/InsertionSort.hpp"


int main(void)
{
    std::vector<U32> array_of_numbers = { 5, 8, 10, 2, 3, 5 };
    InsertionSort(array_of_numbers);

    return 0;
}