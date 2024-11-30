#include <string>

static int
func()
{
    static int result = 1;
    return result++;
}

static std::string str = "abcd";
