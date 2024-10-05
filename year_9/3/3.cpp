#include <iostream>

void
print_array(const int *arr, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[] << " ";
    }
    std::cout << std::endl;
}

int
main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_array(arr, 10);
    return 0;
}
