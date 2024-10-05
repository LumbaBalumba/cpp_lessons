#include <iostream>

int
main()
{
    double y = 1e101;
    double x = -y;
    double z = 1.0;
    double v1 = x + (y + z);
    double v2 = (x + y) + x;
    std::cout << (v1 == v2) << std::endl;
}
