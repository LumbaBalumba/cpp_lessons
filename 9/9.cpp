#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <list>

int
main()
{
    std::unordered_map<int, double> map = {{ 1,  5.0 },
                                           { -1, 4.10 },
                                           { 0,  5.2 }};
    for (std::pair<int, double> elem: map) {
        std::cout << elem.first << " " << elem.second << std::endl;
    }

    std::unordered_set<std::string> set = { "dddddd", "832hrnfun9872fj9mi01j90d10", "abc", "cccc", "52" };
    for (auto &elem: set) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::stack<int> stack;
    stack.push(5);
    int a = stack.top();
    stack.pop();
    std::cout << a << std::endl;

    std::queue<int> queue; //Daniel

    std::deque<int> deque; //Cooler Daniel

    deque.push_back(5);
    deque.pop_front();

    std::list<int> list = { 3, 5, 1, 6, 2, 7, 8 };
    auto it = list.begin();
    it++ ++ ++;
    *it = 2; //list[3] = 2;
}
