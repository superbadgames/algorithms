#include "pch.h"
#include "framework.hpp"

template <typename T>
T* DoubleArraySize(T* array, U32 sizeOfArray)
{
    U32 newArraySize = sizeOfArray * 2;
    T* new_array = new T[newArraySize];

    for (U32 i = 0; i < sizeOfArray; ++i)
    {
        new_array[i] = array[i];
    }

    return new_array;
}