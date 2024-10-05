#include <string>
#include <iostream>

class A
{
private:
    int a{};
    int b{};

protected:
    std::string c;


public:

    A() = default;

    A(int a, int b, const std::string &c) : a(a), b(b), c(c)
    {
    }


    void
    f() const
    {
        std::cout << c << std::endl;
    }

    static void
    staticmethod()
    {
        std::cout << 123 << std::endl;
    }
};

class B
{
    int v{};

public:
    B() = default;

    explicit B(int v) : v(v)
    {}

    void
    f() const
    {
        std::cout << v << std::endl;
    }
};

class C : public A, public B
{
public:
    C() = default;

    using B::f;
    using A::staticmethod;
};

//a[i] == *(a + i) == *(i + a) == i[a]

int
main()
{
    int a = 4;
    int *pa = &a;
    std::cout << *pa << std::endl;
}

