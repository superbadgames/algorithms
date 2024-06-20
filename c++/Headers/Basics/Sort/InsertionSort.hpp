#include "pch.h"
#include "framework.hpp"
#include <vector>
using std::vector;

#include <iostream>

void InsertionSort(vector<U32>& array)
{
    U32 length = (U32)array.size();
    std::cout << "The array is " << length << " elements long\n"
        << "Insertion Sort will re-arrange the array to be in the correct order.\n"
        << "Currently, this is the array:\n";

    for (U32 i = 0; i < length; ++i)
    {
        std::cout << array[i] << ",";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // Assume the first element is already in the correct order
    // start with second element.
    std::cout << "In the for loop: going over the array. Here is what it looks like at the start:\n";

    for (U32 printer = 0; printer < length; ++printer)
    {
        std::cout << array[printer] << ",";
    }

    std::cout << std::endl;

    for (U32 forIndex = 1; forIndex < length; ++forIndex)
    {
        std::cout << "forIndex: " << forIndex << std::endl;
        U32 key = array[forIndex];
        // Iterate over array, place key in correct location
        S32 whileIndex = forIndex - 1;
        while (whileIndex >= 0 && array[whileIndex] > key)
        {
            std::cout << "in the while, j = " << whileIndex << std::endl;
            array[whileIndex + 1] = array[whileIndex];
            --whileIndex;
            std::cout << "end of one while iteration. whileIndex is now " << whileIndex << std::endl;
        }
        std::cout << "while loop just ended\n";
        array[whileIndex + 1] = key;
        std::cout << "end of one iteration. Here's the array now:" << std::endl;

        for (U32 printer = 0; printer < length; ++printer)
        {
            std::cout << array[printer] << ",";
        }
        std::cout << std::endl;
    }
}