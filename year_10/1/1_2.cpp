#include <print>

int main() {
    int *p = new int(5);
    std::println("{}", *p);
    delete p;
}
