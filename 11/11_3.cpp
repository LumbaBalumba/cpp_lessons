#include <iostream>
#include <utility>

int
main(int argc, char *argv[])
{
    std::string a = "abcd";
    auto b = std::move(a);
    std::cout << a << " " << b << std::endl;
    return 0;
}
