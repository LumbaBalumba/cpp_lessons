#include <map>
#include <print>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

int
main()
{
    // std::set<long long> s{4, 5, 6, 3, 2, 1, 7};
    // s.insert(45);
    //
    // for (auto elem: s) {
    //     std::println("{}", elem);
    // }
    //
    //
    // std::map<std::string, int> m{{"a", 1}, {"b", 2}, {"c", 3}};
    // m["d"] = 5;
    //
    // // for (auto &[key, value]: m) {
    // //     std::println("{} {}", key, value);
    // // }
    //
    //
    // for (auto it = m.begin(); it != m.end(); ++it) {
    //     std::println("{} {}", it->first, it->second);
    // }


    std::unordered_set<long long> s{4, 5, 6, 3, 2, 1, 7};
    s.insert(45);

    for (auto elem: s) {
        std::println("{}", elem);
    }
    std::unordered_map<std::string, int> m{{"a", 1}, {"b", 2}, {"c", 3}};
    m["d"] = 5;

    for (auto &[key, value]: m) {
        std::println("{} {}", key, value);
    }


    for (auto it = m.begin(); it != m.end(); ++it) {
        std::println("{} {}", it->first, it->second);
    }
}
