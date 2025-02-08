#include <array>
#include <mutex>
#include <thread>

using namespace std::literals;

enum State
{
    SLEEPING,
    HUNGRY,
    EATING
};

template<size_t N_PHILOSOPHERS>
struct Philosophers {
    std::mutex m;
    std::array<std::mutex, N_PHILOSOPHERS> forks;
    std::array<State, N_PHILOSOPHERS> philosophers;


    void
    test(int i)
    {
        if (philosophers[i] == HUNGRY && philosophers[(i - 1) % N_PHILOSOPHERS] != EATING && philosophers[(i + 1) % N_PHILOSOPHERS] != EATING) {
            philosophers[i] = EATING;
            forks[i].unlock();
        }
    }

    void
    eat(int)
    {
        std::this_thread::sleep_for(250ms);
    }

    void
    take_forks(int i)
    {
        m.lock();
        philosophers[i] = HUNGRY;
        test(i);
        m.unlock();
        forks[i].lock();
    }

    void
    put_forks(int i)
    {
        m.lock();
        philosophers[i] = SLEEPING;
        test((i - 1) % N_PHILOSOPHERS);
        test((i + 1) % N_PHILOSOPHERS);
        m.unlock();
    }

    void
    sleep(int)
    {
        std::this_thread::sleep_for(500ms);
    }

    void
    run();
};
