#include <iostream>

class A
{
private:
    int a;
    int b;

public:
    A() = default;

    A(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    A(int value)
    {
        a = b = value;
    }

    A(const A &a)
    {
        this->a = a.a;
        this->b = a.b;
    }

    int
    get_a() const
    {
        return a;
    }

    int
    get_b() const
    {
        return b;
    }

    void
    set_a(int value)
    {
        a = value;
    }

    void
    set_b(int value)
    {
        b = value;
    }
};

void
print(const A &a)
{
    std::cout << a.get_a() << " " << a.get_b() << std::endl;
}


const char *
foo()
{
    return "abcd";
}


int
main(int argc, char *argv[])
{
    A a;
    a.set_a(5);
    a.set_b(2);
    print(a);
    std::cout << sizeof(a) << std::endl;
    return 0;
}
