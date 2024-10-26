#include <list>
#include <print>

int
main()
{
    std::list<int> l;
    l.push_back(2);
    l.push_front(3);
    l.push_back(4);

    auto it = l.begin();
    it++;
    *it = 1;


    for (auto elem: l) {
        std::println("{}", elem);
    }
}
