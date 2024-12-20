#include "pch.h"
#include "framework.hpp"
#include <iostream>

// Implemented with an array
template<typename T>
class Stack
{
public:
    Stack(void) :
        _sizeOfStack(0),
        _sizeOfArray(1),
        _top(0),
        _array(new T[_sizeOfArray]{ 0 })
    {

    }

    ~Stack(void)
    {
        delete[] _array;
    }

    void Push(T value)
    {
        // If this is the first time Push is called, of if the stack is very small
        if (_sizeOfStack == 0)
        {
            _array[_top] = value;
            ++_sizeOfStack;
            return;
        }
        else if (_sizeOfStack == _sizeOfArray)
        {
            _DoubleArray();
        }
        ++_top;
        _array[_top] = value;
        ++_sizeOfStack;
    }

    T Pop(void)
    {
        T value{ 0 };

        if (_sizeOfStack > 0)
        {
            value = _array[_top];
            // Erase value
            _array[_top] = 0;

            --_top;
            --_sizeOfStack;
        }
        return value;
    }

    void Print(void)
    {
        std::cout << "The Stack\n"
            << "Size of Stack: " << _sizeOfStack << std::endl
            << "Size of Array: " << _sizeOfArray << std::endl;

        for (U32 i = 0; i < _sizeOfArray; ++i)
        {
            std::cout << _array[i] << ", ";
        }
        std::cout << std::endl << "End of Stack\n\n\n";
    }

private:
    U32 _sizeOfStack;
    U32 _sizeOfArray;
    U32 _top;
    T* _array;

    void _DoubleArray(void)
    {
        U32 old_size = _sizeOfArray;
        _sizeOfArray = _sizeOfArray * 2;
        T* new_array = new T[_sizeOfArray]{ 0 };

        for (U32 i = 0; i < old_size; ++i)
        {
            new_array[i] = _array[i];
        }

        _array = new_array;
    }
};

