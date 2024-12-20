#include "pch.h"
#include "framework.hpp"

#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
T BinarySearch(std::vector<T> array, T target)
{
    U32 highIndex = array.size() - 1;
    U32 lowIndex = 0;

    while (lowIndex <= highIndex)
    {
        U32 midIndex = (U32)std::floor((highIndex + lowIndex) / 2);

        if (array[midIndex] == target)
        {
            // Found the target, return the index location
            return midIndex;
        }
        else if (array[midIndex] < target)
        {
            // Not in the bottom half, move low up
            lowIndex = midIndex + 1;
        }
        else // array[midIndex] > target
        {
            // Not in the top half, move high down
            highIndex = midIndex - 1;
        }
    }
    // Target not found, return error state
    return -1;
}
