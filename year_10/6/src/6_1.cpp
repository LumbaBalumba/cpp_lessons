// #include "func.hpp"
#include <print>

struct A {
    inline static int a = 5;

    static int
    b()
    {
        static int b = 0;
        return a + b++;
    }
};


int
main()
{
    for (int i = 0; i < 5; ++i) {
        std::println("{}", A::b());
    }
}
