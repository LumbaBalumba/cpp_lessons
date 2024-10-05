#include <cstddef>
#include <iostream>
#include <ostream>

template<class T>
class DynArray
{
private:
    T *array_;
    size_t size_;
    size_t cap_;

public:
    DynArray()
    {
        array_ = new T[8];
        size_ = 0;
        cap_ = 8;
    }

    DynArray(DynArray &&other) : array_(other.array_), size_(other.size_), cap_(other.cap_)
    {
        other.array_ = nullptr;
        other.cap_ = 0;
        other.size_ = 0;
    }

    DynArray(const DynArray &other)
    {
        //todo
    }

    const DynArray &
    operator=(const DynArray<T> &other)
    {
        //todo
        return *this;
    }

    ~DynArray() noexcept
    {
        delete[] array_;
    }

    T &
    append(int value)
    {
        if (size_ < cap_) {
            array_[size_++] = value;
            return array_[size_ - 1];
        } else {
            T *tmp_array = new T[cap_ * 2];
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

    [[deprecated]] T &
    get(size_t index)
    {
        return array_[index];
    }

    [[nodiscard]] const T &
    operator[](size_t index) const
    {
        return array_[index];
    }

    T &
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
    DynArray<int> arr;

    for (int i = 0; i < 5; ++i) {
        arr.append(i * i);
    }

    std::cout << arr << std::endl;

    arr.remove(3);

    std::cout << arr << std::endl;

    arr.get(5);//deprecated

    return 0;
}
