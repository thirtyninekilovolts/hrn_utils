#include "singletone_base.hpp"
#include <iostream>

using namespace hrn_utils;

class A : public SingletonBase<A>
{
    public:
    void print(const std::string& s)
    {
        std::cout << s << '\n';
    }

};

int main(int argc, char** argv)
{
    auto a = A::getInstance();
    auto b = a;
    b->print("asdasd");
    return 0;
}