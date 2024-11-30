#include <cstdint>
#include <print>

template<uint64_t n>
uint64_t
fact();

template<>
uint64_t
fact<0>()
{
    return 1;
}

template<uint64_t n>
uint64_t
fact()
{
    return n * fact<n - 1>();
}

int
main(int argc, char *argv[])
{
    std::println("{}", fact<5>());
    return 0;
}
