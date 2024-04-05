#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <functional>
#include <thread>
#include <cmath>

//const size_t NUM_THREADS = 4;

//template<class T>
//double
//sum(std::vector<T> &vec)
//{
//    for (size_t i = 0; i < NUM_THREADS - vec.size() % NUM_THREADS; ++i) {
//        vec.push_back(T{});
//    }
//    std::vector<std::thread> threads(NUM_THREADS);
//    std::vector<double> partial_sums;
//    size_t subvector_size = static_cast<double>(std::ceil(
//            static_cast<double>(vec.size()) / static_cast<double>(NUM_THREADS)));
//    for (size_t i = 0; i < NUM_THREADS; ++i) {
//        threads[i] = std::thread([&vec, &partial_sums, subvector_size, i]() {
//            T result{};
//            for (auto it = vec.begin() + i * subvector_size;
//                 it != vec.begin() + i * subvector_size + subvector_size; ++it) {
//                result += *it;
//            }
//            partial_sums.push_back(result);
//        });
//    }
//    T result{};
//    for (auto &thread: threads) {
//        thread.join();
//        result += *(partial_sums.end() - 1);
//    }
//    return result;
//}

int
sum(const std::vector<int> &vec)
{
    return 0;
}

int
main(int argc, char *argv[])
{
    std::vector a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    a.erase(a.begin() + 4);
    for (auto elem: a) {
        std::cout << elem << std::endl;
    }
    std::map<int, double> map = {{ 1,  5.0 },
                                 { -1, 4.10 },
                                 { 0,  5.2 }};
    for (std::pair<int, double> elem: map) {
        std::cout << elem.first << " " << elem.second << std::endl;
    }
    return 0;
}
