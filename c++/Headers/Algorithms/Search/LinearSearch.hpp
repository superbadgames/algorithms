#include "pch.h"
#include "framework.hpp"
#include <vector>

template <typename T>
S32 LinearSearch(std::vector<T> array, T target)
{
    U32 i = 0;
    while (i < array.size())
    {
        if (array[i] == target)
        {
            return i;
        }
        ++i;
    }
    return -1;
}