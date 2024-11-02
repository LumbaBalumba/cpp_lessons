#include <print>
#include <vector>

int
main()
{
    std::vector<int> v{1, 2};
    for (auto it = v.rbegin(); it < v.rend(); ++it) {
        v.push_back(*it);
    }
}
