#include <iostream>
#include <ostream>

int *
f(int a, int b)
{
    int *res = nullptr;
    // res = new int[...];
    return res;
}

int
main()
{
    int n;
    std::cin >> n;
    int *arr = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
}
