#include <memory>
#include <print>
#include <vector>

int
main()
{
    // std::shared_ptr<std::vector<int>> ptr1;
    auto ptr1 = std::make_shared<std::vector<int>>();
    ptr1->push_back(4);
    ptr1->push_back(5);
    ptr1->push_back(3);
    {
        std::weak_ptr ptr2 = ptr1;
        ptr2.lock()->push_back(3);
        for (const auto &elem: *ptr2.lock()) {
            std::println("{}", elem);
        }
    }
    for (const auto &elem: *ptr1) {
        std::println("{}", elem);
    }
}
