#include <iostream>
#include <map>
#include <set>
#include <vector>

int
main(int argc, char *argv[])
{
    std::vector v1 = {1, 2, 3, 4};
    v1[2] = 0;
    v1[1] += v1[2];
    //v1[400000]; //UB
    //size_t == unsigned long
    for (size_t i = 0; i < v1.size(); ++i) {
        int &elem = v1[i];
        std::cout << v1[i] << std::endl;
    }

    std::cout << std::endl;

    for (int elem: v1) {
        std::cout << elem << std::endl;
    }

    for (int &elem: v1) {
        elem += 1;
    }

    for (int elem: v1) {
        std::cout << elem << std::endl;
    }
    return 0;
}
