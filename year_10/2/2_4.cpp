#include <iostream>
#include <print>

int
main()
{
    int a[100];
    std::cout << a << std::endl;

    1 [a] = 5;
    // *(1 + a) = 5;

    std::println("{}", a[1]);// *(a + 1)
}
