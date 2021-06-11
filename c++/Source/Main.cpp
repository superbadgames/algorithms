#include "framework.hpp"
#include <iostream>
#include <chrono>
#include <array>

using std::cout;
using std::endl;

typedef std::chrono::high_resolution_clock Clock;

const U32 MAX_NAMES = 1000;

void FindNemo(std::array<string, MAX_NAMES> names)
{
    string nemo = "nemo";
    auto begin = Clock::now();
    U32 foundCount = 0;

    for(int i = 0; i < MAX_NAMES; ++i)
    {
        if(nemo.compare(names[i]) == 0)
        {
           ++foundCount;
        }
    }
    // This is interesting, but nothing else. It doesn't really say anything other than how well my computer can run this block.
    // Instead of worrying about this. worry about BigO().
    // I am keeping this in the file so that I can look at it later to remember how to get a timer to work, since Tower is going
    // to need its own timer soon enough!
    cout << "Found nemo " << foundCount << " times." << endl;

    auto end = Clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    cout << "FindNemo took " << diff.count() << " microseconds to run." << endl;
}

int main(void)
{
    cout << "hello fuckers!" << endl;
    std::array<string, MAX_NAMES> names {"nemo", "dory", "bruce", "marlin", "gill", "bloat", "nigel", "squirt", "darla", "hank"};

    int namesIndex = 1;
    for(int i = 10; i < MAX_NAMES; ++i)
    {
        names[i] = names[namesIndex];

        ++namesIndex;
        if(namesIndex == 10)
        {
            namesIndex = 1;
        }
    }

    FindNemo(names);

    return 0;
}