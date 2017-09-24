#include "sample.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

class TestInitList
{
public:
    TestInitList()
    {
        std::cout << "Use default ctor.\n";
    }

    TestInitList(const TestInitList& t)
    {
        std::cout << "Use copy ctor.\n";
    }

    TestInitList(std::initializer_list<TestInitList> list)
    {
        _t = list.begin()->_t;
        std::cout << "Use intializer ctor.\n";
    }

    TestInitList(std::initializer_list<int> list)
    {
        std::cout << "Use int intializer ctor.\n";
    }

private:
    int _t = 0;
};

void intializer_list_sample()
{
    std::vector<int> vectorSample = { 1,2,3,4,5 };

    std::map<std::string, std::string> mapSample = { {"a", "peter"}, {"b", "Tom"} };

    int i = 0;
    //List initialization does not allow narrowing
    // char c{ i }; // the benifit of initializer_list rather than c = i, l-value must be able to hold the r-value
    auto j{ i };
    std::cout << "type of j is " << typeid(j).name() << std::endl;

    TestInitList t;
    TestInitList t1{ t }; // copy ctor
    TestInitList t0 = { t }; // copy ctor
    TestInitList t3{ 1,2,3 }; // int list ctor.
    TestInitList t2 { t, t }; // t to list(copy) t to list(copy) list to t2(initlist ctor)
}