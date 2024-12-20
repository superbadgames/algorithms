#include "pch.h"
#include "framework.hpp"

#include <iostream>

template<typename T>
struct LinkedListNode
{
    T value;
    shared_ptr<LinkedListNode> next;
};

template<typename T>
class LinkedList
{
public:
    LinkedList(void) :
        _front(nullptr)
    {
    }


    LinkedList(const LinkedList& list) :
        _front(list.GetFront())
    {
    }


    ~LinkedList(void)
    {
        _front.reset();
    }


    LinkedList& operator=(const LinkedList& list)
    {
        if (this == list) return *this;

        _front = list.GetFront();
        return *this;
    }


    T operator[](std::size_t index)
    {
        shared_ptr<LinkedListNode<T>> node = GetNode(index);

        if (node == nullptr)
        {
            std::cout << "Error! There is no value at " << index << std::endl;
            return 0;
        }

        return node->value;
    }

    shared_ptr<LinkedListNode<T>> GetNode(std::size_t index)
    {
        shared_ptr<LinkedListNode<T>> current = _front;
        U32 count = 0;

        while (count < index and current != nullptr)
        {
            current = current->next;
            ++count;
        }

        if (current == nullptr)
        {
            std::cout << "Error! index " << index << " is out of range!\n";
        }

        return current;
    }


    shared_ptr<LinkedListNode<T>> GetFront(void) const
    {
        return _front;
    }


    shared_ptr<LinkedListNode<T>> GetEnd(void) const
    {
        shared_ptr<LinkedListNode<T>> current = _front;

        while (current->next != nullptr)
        {
            // Check if we are there yet
            if (current->next == nullptr)
            {
                return current;
            }

            current = current->next;
        }

        // This is an error state!
        return nullptr;
    }

    void InsertAfter(shared_ptr<LinkedListNode<T>> previous_node, shared_ptr<LinkedListNode<T>> new_node)
    {
        new_node->next = previous_node->next;
        previous_node->next = new_node;
    }

    void InsertEnd(T value)
    {
        shared_ptr<LinkedListNode<T>> end = GetEnd();
        shared_ptr<LinkedListNode<T>> new_node = std::make_shared<LinkedListNode<T>>();
        new_node->value = value;

        end->next = new_node;
        new_node->next = nullptr;
    }

    void Insert(T value, U32 location)
    {
        // Check if location is a new top
        if (location == 0)
        {
            shared_ptr<LinkedListNode<T>> node = std::make_shared<LinkedListNode<T>>();
            node->value = value;
            node->next = _front;
            _front = node;
            return;
        }

        // Get the node currently located at location
        shared_ptr<LinkedListNode<T>> current_node = GetNode(location - 1);

        // Check for nullptr
        if (current_node == nullptr)
        {
            // Assume the end is cool, insert at the end
            InsertEnd(value);
        }

        shared_ptr<LinkedListNode<T>> new_node = std::make_shared<LinkedListNode<T>>();
        new_node->value = value;
        InsertAfter(current_node, new_node);
    }



private:
    U32 _count;
    shared_ptr<LinkedListNode<T>> _front;
};
