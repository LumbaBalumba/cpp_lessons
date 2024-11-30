#include <cstddef>
#include <print>
#include <string>
#include <tuple>

struct MyStruct {
    char c;
    int i;
};

int
main(int argc, char *argv[])
{
    std::tuple<int, std::string, float, std::nullptr_t> t{4, "Hello world", 0.1, nullptr};
    std::println("{}", std::get<int>(t));

    auto [a, b, c, d] = t;
    std::println("{} {} {} {}", a, b, c, d);

    MyStruct s{'a', 5};
    auto [e, f] = s;


    std::pair pair{5, "abcd"};
    auto [g, h] = pair;
    pair.first += 3;
    std::println("{} {}", pair.first, pair.second);
}
