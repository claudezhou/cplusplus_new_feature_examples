#include "sample.h"
#include <iostream>
// constexpr tells compiler to check if this is a value can be decided at compiler time
// which optimize the runtime performance.
constexpr int fibonacci(const int n)
{
    return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

void constexprSample()
{
    // since fibonacci is constexpr and can be decided during compile time, 
    //  it is legal here.
    int intArray[fibonacci(3)];
    std::cout << "array count is " << sizeof(intArray) << std::endl;
}