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
    private:
    friend SingletonBase<A>;
    A (int i)
    {
        std::cout << i << '\n';
    }

};

int main(int argc, char** argv)
{
    auto a = A::getInstance(2);
    return 0;
}