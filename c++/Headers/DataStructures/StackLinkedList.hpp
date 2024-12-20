#include "pch.h"
#include "framework.hpp"
#include "DataStructures/LinkedList.hpp"
#include <iostream>

// Implemented with a linked list
template <typename T>
class Stack_LinkedList
{
public:
    Stack_LinkedList(void) :
        _sizeOfStack(0),
        _head(nullptr)
    {
    }

    ~Stack_LinkedList(void)
    {

    }

    void Push(T value)
    {
        shared_ptr<LinkedListNode<T>> new_node = std::make_shared<LinkedListNode<T>>();
        new_node->value = value;
        // First, and last node
        if (_sizeOfStack == 0)
        {
            new_node->next = nullptr;
        }
        else
        {
            new_node->next = _head;
        }

        _head = new_node;
        ++_sizeOfStack;
    }

    T Pop(void)
    {
        T value = 0;
        if (_sizeOfStack > 0)
        {
            value = _head->value;
            _head = _head->next;
            --_sizeOfStack;
        }
        return value;
    }

    void Print(void)
    {
        std::cout << "The Stack\n"
            << "Size = " << _sizeOfStack << std::endl;

        shared_ptr<LinkedListNode<T>> current = _head;


        while (current != nullptr)
        {
            std::cout << current->value << ", " << std::endl;
            current = current->next;
        }
        std::cout << "End of Stack\n\n\n";
    }

private:
    U32 _sizeOfStack;
    shared_ptr<LinkedListNode<T>> _head;
};