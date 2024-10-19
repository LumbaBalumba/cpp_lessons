#include <print>

int
main()
{
    int a;

    int *pa = nullptr, *pb = nullptr;
    pa = &a;
    *pa = 3;
    std::println("{}", a);

    int &ra = a;
    ra += 1;
    std::println("{}", a);
}
