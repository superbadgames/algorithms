#include "pch.h"
#include "framework.hpp"
#include "Demos.h"
#include "Algorithms/Sort/InsertionSort.hpp"

#include <vector>
#include <iostream>

void InsertionSortDemo(void)
{
    std::cout << "Insertion Sort Demo\n"
        << "An array of numbers will be created with the following values:\n";
    std::vector<U32> array_of_numbers = { 5, 8, 10, 2, 3, 5 };

    for (U32 i : array_of_numbers)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    std::cout << "Sort the array... ... ...\n";

    InsertionSort<U32>(array_of_numbers);

    std::cout << "The array is now in the following order:\n";

    for (U32 i : array_of_numbers)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl << "End of Insertion Sort Demo\n";
}