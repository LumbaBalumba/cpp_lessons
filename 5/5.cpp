#include <cstddef>
#include <iostream>
#include <ostream>

class DynArray
{
private:
    int *array_;
    size_t size_;
    size_t cap_;

public:
    DynArray()
    {
        array_ = new int[8];
        size_ = 0;
        cap_ = 8;
    }

    ~DynArray() noexcept
    {
        delete[] array_;
    }

    int &
    append(int value)
    {
        if (size_ < cap_) {
            array_[size_++] = value;
            return array_[size_ - 1];
        } else {
            int *tmp_array = new int[cap_ * 2];
            if (tmp_array == nullptr) {
                //error
            }
            for (size_t i = 0; i < size_; ++i) {
                tmp_array[i] = array_[i];
            }
            tmp_array[size_++] = value;
            array_ = tmp_array;
            return array_[size_ - 1];
        }
    }

    [[deprecated]] int &
    get(size_t index)
    {
        return array_[index];
    }

    [[nodiscard]] const int &
    operator[](size_t index) const
    {
        return array_[index];
    }

    int &
    operator[](size_t index)
    {
        return array_[index];
    }

    size_t
    size() const
    {
        return size_;
    }

    void
    remove(size_t index)
    {
        for (size_t i = index; i < size() - 1; ++i) {
            array_[i] = array_[i + 1];
        }
        size_--;
    }

    friend std::ostream &
    operator<<(std::ostream &out, const DynArray &arr)
    {
        out << "[ ";
        for (size_t i = 0; i < arr.size(); ++i) {
            out << arr[i] << " ";
        }
        out << "]";
        return out;
    }
};


int
main(int argc, char *argv[])
{

    int a = 5;
    // int b = a++;//b = 5
    // int b = ++a;//b = 6

    int &d = a;
    int *e = &a;

    std::cout << d << " " << e << std::endl;
    DynArray arr;

    for (int i = 0; i < 5; ++i) {
        arr.append(i * i);
    }

    std::cout << arr << std::endl;

    arr.remove(3);

    std::cout << arr << std::endl;

    arr.get(5);//deprecated


    return 0;
}
