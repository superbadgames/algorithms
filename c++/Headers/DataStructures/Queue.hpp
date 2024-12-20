#include "pch.h"
#include "framework.hpp"
#include "Utils/DoubleArraySize.hpp"

#include <iostream>

template <typename T>
class Queue
{
public:
    Queue(void) :
        _front(0),
        _back(0),
        _queueSize(0),
        _maxQueueSize(8),
        _arraySize(1),
        _array(new T[_arraySize]{ 0 })
    {

    }

    ~Queue(void)
    {
        delete[] _array;
    }

    void Push(T value)
    {
        // Make sure we have room, if we need it, and if we can have it
        if (_arraySize == _queueSize and _queueSize < _maxQueueSize)
        {
            _array = DoubleArraySize<T>(_array, _arraySize);
            _arraySize *= 2;
        }

        if (IsFull())
        {
            return;
        }


        ++_back;

        if (_back == _arraySize)
        {
            _back = 0;
        }

        _array[_back] = value;
        ++_queueSize;

        if (_queueSize == 1)
        {
            _front = _back;
        }
    }

    T Pop(void)
    {
        if (IsEmpty())
        {
            std::cout << "ERROR! Queue is empty. Returning 0\n";
            return 0;
        }

        T value = _array[_front];
        --_queueSize;
        ++_front;

        if (_front == _arraySize)
        {
            _front = 0;
        }
        return value;
    }

    void Print(void)
    {
        std::cout << "The Queue:\n"
            << "Queue Size: " << _queueSize << std::endl
            << "Array Size: " << _arraySize << std::endl
            << "Front: " << _front << std::endl
            << "Back: " << _back << std::endl;


        for (U32 i = 0; i < _arraySize; ++i)
        {
            std::cout << _array[i] << ", ";
        }
        std::cout << std::endl << "End of Queue\n";
    }

    bool IsEmpty(void)
    {
        if (_queueSize == 0)
        {
            return true;
        }
        return false;
    }

    bool IsFull(void)
    {
        if (_queueSize == _arraySize)
        {
            return true;
        }
        return false;
    }

private:
    U32 _front;
    U32 _back;
    U32 _queueSize;
    U32 _maxQueueSize;
    U32 _arraySize;
    T* _array;
};