#include "pch.h"
#include "framework.hpp"
#include <vector>
using std::vector;

#include <iostream>

template <typename T>
void InsertionSort(vector<T>& array)
{
    U32 length = (U32)array.size();
    // Assume the first element is already in the correct order
    // start with second element.
    for (U32 i = 1; i < length; ++i)
    {
        U32 key = array[i];
        // Iterate over array, place key in correct location
        S32 j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
