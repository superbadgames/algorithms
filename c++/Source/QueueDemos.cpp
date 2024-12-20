#include "pch.h"
#include "framework.hpp"
#include "Demos.h"
#include "DataStructures/Queue.hpp"

#include <iostream>

void QueueAsArrayDemo(void)
{
    std::cout << "Queue as an Array Demo\n"
        << "Create the queue\n";

    Queue<U32> queue{};

    std::cout << "Print the Default queue\n";

    queue.Print();

    std::cout << "Add the first 5 prime numbers to the queue. This will cause the array to double\n";

    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Push(5);
    queue.Push(7);

    queue.Print();

    std::cout << "Pop off the first value\n\n\n";

    U32 value = queue.Pop();

    std::cout << "The value I got was " << value << std::endl << std::endl;

    queue.Print();

    std::cout << "Now I will add a few more values, and cause the queue to fill, until I get an error\n\n\n";

    queue.Push(11);
    queue.Push(13);
    queue.Push(17);

    std::cout << "The next push should fail\n\n\n";

    queue.Push(100);
    queue.Push(101);

    queue.Print();

    std::cout << "Now to Pop a few more off\n\n\n";

    std::cout << "Pop: " << queue.Pop() << std::endl;
    std::cout << "Pop: " << queue.Pop() << std::endl;
    std::cout << "Pop: " << queue.Pop() << std::endl;

    queue.Print();

    std::cout << "Add a few more, to test that the wrapping is working as expected\n\n\n";

    queue.Push(103);
    queue.Push(104);
    queue.Push(105);

    queue.Print();

    std::cout << "The next push should fail\n\n\n";

    queue.Push(106);
    queue.Print();

    std::cout << "Clear the queue until empty\n\n\n";

    std::cout << "Pop: " << queue.Pop() << std::endl;
    std::cout << "Pop: " << queue.Pop() << std::endl;
    std::cout << "Pop: " << queue.Pop() << std::endl;
    std::cout << "Pop: " << queue.Pop() << std::endl;
    std::cout << "Pop: " << queue.Pop() << std::endl;
    std::cout << "Pop: " << queue.Pop() << std::endl;
    std::cout << "Pop: " << queue.Pop() << std::endl;
    std::cout << "Pop: " << queue.Pop() << std::endl;

    std::cout << "The next pop should fail\n";
    std::cout << "Pop: " << queue.Pop() << std::endl;

    queue.Print();

    std::cout << "Pushing 1 value, to test that logic for empty queue works\n\n\n";

    queue.Push(1000);
    queue.Print();

    std::cout << "Pop that last value: " << queue.Pop() << std::endl;

    std::cout << "End of the Queue as an Array Demo\n\n\n";
}