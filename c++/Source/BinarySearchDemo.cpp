#include "pch.h"
#include "framework.hpp"
#include "Demos.h"
#include "Algorithms/Search/BinarySearch.hpp"

#include <iostream>

void BinarySearchDemo(void)
{
    std::cout << "Binary Search will return the index that a target is located at in the array. If the target cannot be found, -1 will be returned.\n";
    std::cout << "Here is the array: \n\n";
    std::vector<S32> array = { 2, 5, 6, 7, 12, 15, 23, 45, 67, 89, 123, 456, 789 };
    for (auto i : array)
    {
        std::cout << i << ",";
    }
    std::cout << std::endl;

    std::cout << "First, check for 7\n";
    S32 i = BinarySearch<S32>(array, 7);

    if (i == -1)
    {
        std::cout << "The value 7 was not found in the list";
    }
    else
    {
        std::cout << "The value 7 was found at index " << i << std::endl;
    }

    std::cout << "Next, check for a number that doesn't exist, 54\n";

    i = BinarySearch<S32>(array, 54);

    if (i == -1)
    {
        std::cout << "The value 54 was not found in the list\n";
    }
    else
    {
        std::cout << "The value 54 was found at index " << i << std::endl;
    }

    std::cout << "Last, look for 456\n";

    i = BinarySearch<S32>(array, 456);

    if (i == -1)
    {
        std::cout << "The value 456 was not found in the list";
    }
    else
    {
        std::cout << "The value 456 was found at index " << i << std::endl;
    }
}