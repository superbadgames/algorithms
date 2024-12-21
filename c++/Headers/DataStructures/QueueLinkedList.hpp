#include "pch.h"
#include "framework.hpp"
#include "DataStructures/LinkedList.hpp"

#include <iostream>

template <typename T>
class Queue_LinkedList
{
public:
    Queue_LinkedList(void) :
        _front(nullptr),
        _back(nullptr),
        _sizeOfQueue(0)
    {

    }

    ~Queue_LinkedList(void)
    {

    }

    void Push(T value)
    {
        shared_ptr<LinkedListNode<T>> node = std::make_shared<LinkedListNode<T>>();
        node->value = value;
        node->next = nullptr;

        if (_sizeOfQueue == 0)
        {
            _front = node;
            _back = node;
            ++_sizeOfQueue;
            return;
        }

        _back->next = node;
        _back = node;
        ++_sizeOfQueue;
    }

    T Pop(void)
    {
        if (_sizeOfQueue == 0)
        {
            std::cout << "ERROR! The queue is empty. Returning 0\n";
            return 0;
        }

        T value = _front->value;
        _front = _front->next;
        --_sizeOfQueue;

        return value;
    }

    void Print(void)
    {
        std::cout << "The Queue:\n"
            << "Size of Queue: " << _sizeOfQueue << std::endl;

        shared_ptr<LinkedListNode<T>> current = _front;

        if (current != nullptr)
        {
            std::cout << "Front value: " << current->value << std::endl;
        }

        while (current != nullptr)
        {
            std::cout << current->value << ", ";
            current = current->next;
        }

        std::cout << std::endl << "End of the Queue\n";
    }

private:
    U32 _sizeOfQueue;
    shared_ptr<LinkedListNode<T>> _front;
    shared_ptr<LinkedListNode<T>> _back;
};