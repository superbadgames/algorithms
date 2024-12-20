#include "pch.h"
#include "framework.hpp"
#include "Demos.h"
#include "Algorithms/Search/LinearSearch.hpp"

#include <iostream>

void LinearSearchDemo(void)
{
    std::vector<S32> array = { 3, 11, 9, 37, 7, 8, 1, 21, 5, 17, 31 };

    std::cout << "Linear Search will return the index that a target is located at in the array. If the target cannot be found, it will return -1\n";

    std::cout << "Here is the array: \n\n";

    for (auto i : array)
    {
        std::cout << i << ",";
    }

    std::cout << "First, check for 37\n...\n...\n...\n" << std::endl;
    S32 i = LinearSearch<S32>(array, 37);

    if (i == -1)
    {
        std::cout << "The value 37 was not found in the list";
    }
    else
    {
        std::cout << "The value 37 was found at index " << i << std::endl;
    }

    std::cout << "Next, check for 51\n...\n...\n...\n";

    i = LinearSearch<S32>(array, 51);

    if (i == -1)
    {
        std::cout << "The value 51 was not found in the list";
    }
    else
    {
        std::cout << "The value 51 was found at index " << i << std::endl;
    }

    std::cout << "End of Linear Search\n";
}