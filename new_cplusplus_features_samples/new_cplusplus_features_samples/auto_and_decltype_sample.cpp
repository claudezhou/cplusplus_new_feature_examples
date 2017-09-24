#include "sample.h"
#include <iostream>

int& foo2()
{
    static int ret = 2;
    return ret;
}

// auto lets compiler decide a var's type.
// best practicle is to work with iterator to save a lot of typo.
void autoSample()
{
    int a = 0;
    auto b = a;
    std::cout << "type of b is " << typeid(b).name() << std::endl;

    auto aptr = new auto(10);
    std::cout << "type of aptr is " << typeid(aptr).name() << std::endl;

    auto d = foo2(); // when c is rvalue reference, the reference will be ignored.
    d = 3;
    std::cout << foo2() << std::endl;
    auto e = (foo2()); // () makes it as lvalue reference.
    e = 4;
    std::cout << foo2() << std::endl;
    // only f is int& other is just int;
    auto& f = foo2();
    f = 5;
    
    std::cout << foo2() << std::endl;
    // typeid(xx) does NOT tell if the type is a REFERENCE or not
    std::cout << "type of d is " << typeid(d).name() << std::endl;
    std::cout << "type of e is " << typeid(e).name() << std::endl;
    std::cout << "type of f is " << typeid(f).name() << std::endl;
}

int foo_int()
{
    return 1;
}

const int foo_cint()
{
    return 2;
}


// decltype keyword lets compiler to deduce the type based on an expression.
// -> means trailing return type.
template<class T>
auto template_func(T t)->decltype(t) // combine auto and decltype in template to decide return type.
{
    return t;
}

template<class T>
auto template_func2(T t)
{
    return t; // in C++ 14, auto can be directly used.
}

void decltype_sample()
{
    int x = 0;
    decltype(foo_int()) a = x; // a is int
    std::cout << "type of a is " << typeid(a).name() << std::endl;

    decltype(foo_cint()) b = x; // b is int since foo_cint() return const int which is a r-value, const will be discarded.
    b = 3;
    std::cout << "type of b is " << typeid(b).name() << std::endl;

    decltype((x)) c = x; // () makes the result as l-value reference
    c = 3;
    std::cout << c << x << std::endl;
    std::cout << "type of c is " << typeid(c).name() << std::endl;
    // ++x is an expression that means x = x+1, 
    // when expression assign value to a l-value, the result is l-value reference.
    decltype(++x) d = x;
    d = 10;
    std::cout << d << x << std::endl;
    std::cout << "type of d is " << typeid(d).name() << std::endl;

    decltype(x + 1) e = x;// x+1 is expression, but it doesn't assign a l-value. so e is int
    std::cout << "type of e is " << typeid(e).name() << std::endl;

    auto result = template_func(1.1f);
    std::cout << "type of result is " << typeid(result).name() << std::endl;

    auto result2 = template_func2(1.1);
    std::cout << "type of result2 is " << typeid(result2).name() << std::endl;
}