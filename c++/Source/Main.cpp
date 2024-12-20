#include "pch.h"
#include "framework.hpp"
#include "Demos.h"

#include <iostream>
#include <cstdlib>

U32 PrintMenuAndGetInput(void)
{
    std::cout << "\n\n\nSelect a demo to see.\n"
        << "0. Exit\n"
        << "1. Clear Screen\n"
        << "2. Insertion Sort\n"
        << "3. Linear Search\n"
        << "4. Binary Search\n"
        << "5. Linked Lists\n"
        << "6. Stack as an Array\n"
        << "7. Stack as Linked List\n"
        << "More to come...\n"
        << std::endl;
    U32 input;
    std::cin >> input;
    return input;
}

void ProcessInput(U32 input)
{
    if (input == 1)
    {
        std::system("cls");
    }
    else if (input == 2)
    {
        InsertionSortDemo();
    }
    else if (input == 3)
    {
        LinearSearchDemo();
    }
    else if (input == 4)
    {
        BinarySearchDemo();
    }
    else if (input == 5)
    {
        LinkedListDemo();
    }
    else if (input == 6)
    {
        StackAsArrayDemo();
    }
    else if (input == 7)
    {
        StackAsLinkedList();
    }
    else
    {
        std::cout << "Error! " << input << " is not a value input option\n";
    }
}

int main(void)
{
    std::cout << "Super Bad Algorithms!\n\n\n";

    U32 input = PrintMenuAndGetInput();

    while (input != 0)
    {
        ProcessInput(input);
        input = PrintMenuAndGetInput();
    }

    std::cout << "\n\n\nThanks! Closing now\n\n\n";

    return 0;
}