#include <cstdio>
#include <format>
#include <print>
#include <string>
#include <vector>

int
main()
{
    // std::vector<int> v{};
    // std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    using vector_content_type = std::string;


    const std::vector<vector_content_type> v{"abcd", "efgh", "ijkl"};


    char s[] = {'a', 'b', 'c', 'd'};
    // const char p[] = "efgh";
    // '\0' == 0
    // s[5] = (char) 13805;
    // std::printf("%s\n", s);

    std::string a = "abcd", b = "efgh";
    a += b;
    auto c = std::format("{} {}", a, b);
    // std::cout << std::format("{} {}", a, b) << std::endl;


    // for (const auto &elem: v) {
    //     std::println("{}", elem);
    // }
    //
    // std::println("\n");
    //
    // for (auto it = v.crbegin(); it < v.crend(); it += 2) {
    //     const auto &elem = *it;
    //     std::println("{}", elem);
    // }
    //

    std::vector<vector_content_type> v1(v.begin() + 1, v.end() - 1);

    for (const auto &elem: v1) {
        std::println("{}", elem);
    }
}
