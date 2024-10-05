#include <string>
#include <iostream>

class A
{
private:
    int a;
    int b;

protected:
    std::string c;


public:

    A() = default;

    A(int a, int b, const std::string &c) : a(a), b(b), c(c)
    {
    }


    virtual void
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

class B : public A
{
    int v;

public:
    B(int a, int b, const std::string &c, int v) : v(v), A(a, b, c)
    {}

    void
    f() const override
    {
        std::cout << v << std::endl;
    }
};

int
main()
{
    A a1, a2;
    a1.staticmethod();
}