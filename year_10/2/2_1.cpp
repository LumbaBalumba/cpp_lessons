#include <print>

int
main()
{
    int a = 5;

    if (a < 3) {
        std::println("Less");
    } else {
        std::println("Greater");
    }

    while (a > 0) {
        a /= 2;
        std::println("{}", a);
    }

    for (int i = 0; i < 10; ++i) {
        std::println("{}", i);
    }

    for (;;) {
        //
        if (a <= 0) {
            break;
        }
        a--;
    }


    do {
        ///
    } while (a > 0);

    int sum = 1;

    for (;;) {
        sum += sum;
    }


    // while (true) {
    //     //
    // }
    //
    // do {
    //
    // } while()
}
