#include "pch.h"
#include "framework.hpp"
#include "Demos.h"
#include "DataStructures/Stack.hpp"
#include "DataStructures/StackLinkedList.hpp"

#include <iostream>

void StackAsArrayDemo(void)
{
    std::cout << "Stack as an Array Demo\n";

    Stack<U32> stack{};

    std::cout << "Default Stack:\n";
    stack.Print();

    std::cout << "Why don't we try to pop off before we add anything?\n";

    U32 value = stack.Pop();
    stack.Print();
    std::cout << "I got value = " << value << std::endl;

    std::cout << "Now, make sure that the array can double without issues. Push the prime numbers 1-11 onto the stack\n...\n";
    stack.Push(1);
    stack.Print();
    stack.Push(2);
    stack.Print();
    stack.Push(3);
    stack.Print();
    stack.Push(5);
    stack.Print();
    stack.Push(7);
    stack.Print();
    stack.Push(11);
    stack.Print();

    std::cout << std::endl << "Now to Pop some values off the Stack\n";

    value = stack.Pop();
    std::cout << "I got " << value << " off the stack\n";
    stack.Print();

    std::cout << "Now to push a new value on!\n";

    stack.Push(100);
    stack.Print();

    std::cout << "End of the Stack Demo\n";
}

void StackAsLinkedList(void)
{
    std::cout << "Stack as Linked List Demo\n\n";

    Stack_LinkedList<U32> stack{};

    std::cout << "Default stack state:\n";

    stack.Print();

    std::cout << "1. Try to pop an empty list\n";

    U32 value = stack.Pop();

    std::cout << "I got value: " << value << std::endl;

    std::cout << "\n2. Add some data. The prime numbers up to 11\n";

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(5);
    stack.Push(7);
    stack.Push(11);

    std::cout << "Here is the stack after pushing those values on:\n";
    stack.Print();

    std::cout << "\n3. Now to pop some values off\n";

    //value = stack.Pop();

    std::cout << "I got value: " << stack.Pop() << "\nThe Stack looks like this:\n";
    stack.Print();

    std::cout << "Pop! I get: " << stack.Pop() << std::endl << "here's the stack:\n";
    stack.Print();

    std::cout << "Pop again! I get: " << stack.Pop() << std::endl;
    std::cout << "Pop again! I get: " << stack.Pop() << std::endl;
    std::cout << "Here is the stack I have remaining:\n";
    stack.Print();

    std::cout << "End of Stack as Linear List Demo\n";
}