#include <array>
#include <print>

int
main()
{
    std::array<double, 4> arr{1, 2, 3, 4};
    for (const auto &elem: arr) {
        std::println("{}", elem);
    }
}
