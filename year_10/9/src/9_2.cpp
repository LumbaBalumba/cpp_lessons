#include <print>
#include <thread>

int
main()
{
    std::jthread th1([]() {
        std::println("Hell from thread 1");
    });
    std::jthread th2([]() {
        std::println("Hell from thread 2");
    });
    th1.join();
    th2.join();
}
