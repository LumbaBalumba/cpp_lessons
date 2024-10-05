#include <print>
#include <cinttypes>
#include <string>

int main() {
    signed int a = 5;
    char b = 1;
    short c = 2;
    int d = 4;
    long e = 10;
    long long f = 8;
    unsigned char g = 1;
    
    int8_t h;
    int16_t i;
    int32_t j;
    int64_t k;

    uint8_t l;
    // ...

    float m = 6.0;
    double n = 9.0;

    std::string s = "Hello";

    std::println("{}", s);
}
