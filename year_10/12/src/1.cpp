#include <array>
#include <cstddef>
#include <mutex>
#include <print>
#include <ranges>
#include <thread>
#include <vector>

std::mutex no_writers, no_readers;
std::atomic<std::size_t> nreaders = 0;

using namespace std::literals;


int counter = 0;


void
writer()
{
    std::this_thread::sleep_for(100ms);
    no_writers.lock();
    no_readers.lock();

    std::println("Writing...");
    counter++;

    no_writers.unlock();
    no_readers.unlock();
}

void
reader()
{
    std::this_thread::sleep_for(100ms);
    no_writers.lock();

    auto prev = nreaders + 0;
    nreaders += 1;
    if (prev == 0) {
        no_readers.lock();
    }

    no_writers.unlock();

    std::println("Counter: {}", counter);

    nreaders -= 1;
    auto current = nreaders + 0;
    if (current == 0) {
        no_readers.unlock();
    }
}

int
main()
{
    constexpr static std::size_t N = 100000;

    std::array<std::jthread, N> readers;
    std::array<std::jthread, N> writers;

    for (auto i: std::views::iota(0, (int) N)) {
        readers[i] = std::jthread(reader);
        writers[i] = std::jthread(writer);
    }
}
