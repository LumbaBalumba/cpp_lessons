#include <iostream>

void
bubblesort(int *arr, size_t size)
{
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int
main()
{
    size_t size;
    std::cin >> size;
    int *arr = new int[size];
    for (size_t i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    bubblesort(arr, size);
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
}
