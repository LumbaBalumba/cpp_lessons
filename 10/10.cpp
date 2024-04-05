#include <string>
#include <iostream>

class A
{
    int a;
    int b;
    std::string c;
};

class A1
{
    char c;
};

class B : A, A1
{

};

int
main()
{
    std::cout << sizeof(A) << " " << sizeof(A1) << " " << sizeof(B) << std::endl;
}