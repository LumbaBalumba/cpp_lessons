#include <atomic>
#include <print>
#include <ranges>
#include <thread>
#include <vector>

int
main()
{
    using namespace std::literals;

    std::atomic<int> state = 0;
    auto threads = std::views::iota(0, 10) |
                   std::views::transform([&state](auto i) {
                       return std::jthread([&state] {
                           while (true) {
                               state++;
                           }
                       });
                   }) |
                   std::ranges::to<std::vector<std::jthread>>();
    while (true) {
        std::this_thread::sleep_for(250ms);
        std::println("{}", state.load());
    }
}
