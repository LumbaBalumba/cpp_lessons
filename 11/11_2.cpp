#include <cpr/cpr.h>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>


void
process_site(const std::string &site, std::mutex *mutex_ptr, int *result)
{
    auto r = cpr::Get(cpr::Url{"http://" + site});
    mutex_ptr->lock();
    std::cout << r.text << std::endl;
    mutex_ptr->unlock();
    *result = 1;
}

int
main(int argc, char *argv[])
{
    std::vector<std::string> sites = {"i3alumba.ru", "habr.com", "vk.com", "youtube.com", "yandex.ru"};
    std::vector<std::thread> threads;
    std::mutex mutex;
    int result;
    for (auto &site: sites) {
        threads.emplace_back(process_site, site, &mutex, &result);
    }

    for (auto &thread: threads) {
        thread.join();
    }
    return 0;
}
