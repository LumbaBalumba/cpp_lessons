#include <complex>
#include <cstdlib>
#include <print>
#include <string>

int
func(int a)
{
    return a + 1;
}

long
func(long a)
{
    return a + 1;
}

std::string
func(std::string a, int b = 4)
{
    return a + "1" + std::to_string(b);
}

int
main()
{
    func(2);
    func(2l);
    func("abcd");
    // abs, fabs, iabs
    std::println("{} {} {} {}", std::abs(-1), std::abs(5.0), std::abs(-2.0f), std::abs(std::complex<double>{-3, 4}));
}
