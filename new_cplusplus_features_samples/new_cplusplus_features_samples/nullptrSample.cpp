#include <iostream>

void foo(int)
{
    std::cout << "int version of foo\n";
}

void foo(char*)
{
    std::cout << "char ptr version of foo \n";
}

void nullptrSample()
{
    foo(0);
    // error prone, NULL is defined as 0.
    foo(NULL);
    foo(nullptr);
}