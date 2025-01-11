#include <fstream>
#include <iostream>
#include <print>

int
main()
{
    std::ifstream in("in.txt");
    std::string s;
    while (in >> s) {
        std::println("{}", s);
    }
    in.close();
}
