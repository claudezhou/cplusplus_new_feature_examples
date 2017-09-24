#include "sample.h"
#include <iostream>
#include <vector>

void range_for_sample()
{
    int array[] = { 1,2,3,4,5 };
    for (auto& i : array) //without & you can't modify the array.
    {
        --i;
        std::cout << array[i] << std::endl;
    }

    std::vector<float> vectorSample(10, 2);
    for (auto& i : vectorSample)
    {
        std::cout << i;
    }
}