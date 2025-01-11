#include <memory>
#include <print>
#include <string>

int
main()
{
    auto ptr1 = std::make_unique<std::string>("abcd");
    std::println("{}", *ptr1);
    auto ptr2 = std::move(ptr1);
    std::println("{}", *ptr2);
}
