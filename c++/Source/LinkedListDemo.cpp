#include "pch.h"
#include "framework.hpp"
#include "Demos.h"
#include "DataStructures/LinkedList.hpp"

#include <iostream>

void LinkedListDemo(void)
{
    std::cout << "1. Create a new linked list and fill it with data\n...\n...\n...\n";
    LinkedList<U32> list{};

    for (U32 i = 0; i < 10; ++i)
    {
        list.Insert(std::rand(), i);
    }

    std::cout << "2. Print the contents of the list, calling the [] operator\n...\n...\n...\n";

    for (std::size_t i = 0; i < 10; ++i)
    {
        std::cout << list[i] << ", ";
    }
    std::cout << std::endl;
}