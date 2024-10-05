#include <cpr/cpr.h>
#include <future>
#include <iostream>
#include <mutex>
#include <string>
#include <vector>

std::mutex mutex;

int
process_site(const std::string &site)
{
    auto r = cpr::Get(cpr::Url{"http://" + site});
    mutex.lock();
    std::cout << r.text << std::endl;
    mutex.unlock();
    return 1;
}

int
main(int argc, char *argv[])
{
    std::vector<std::string> sites = {"i3alumba.ru", "habr.com", "vk.com", "youtube.com", "yandex.ru"};
    std::vector<std::future<int>> futures;
    for (auto &site: sites) {
        futures.push_back(std::async(std::launch::async, process_site, site));
    }
    for (auto &future: futures) {
        std::cout << future.get() << std::endl;
    }
    return 0;
}
