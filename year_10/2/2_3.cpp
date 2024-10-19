#include <print>

int
main()
{
    int a[10];

    a[-1] = 100;

    std::println("{}", a[-1]);
}
