#include <print>
#include <string>
#include <tuple>

template<size_t idx, typename... Ts>
struct Type {
};

template<size_t idx, typename T, typename... Ts>
    requires(idx == 0)
struct Type<idx, T, Ts...> {
    using type = T;
};


template<size_t idx, typename T, typename... Ts>
    requires(idx > 0)
struct Type<idx, T, Ts...> {
    using type = Type<idx - 1, Ts...>::type;
};
///////////////////////////

template<typename... Ts>
struct Tuple {
};

template<typename T>
struct Tuple<T> {
    T value;

    template<size_t idx>
        requires(idx == 0)
    T
    get() noexcept
    {
        return value;
    }
};


template<typename T, typename... Ts>
struct Tuple<T, Ts...> {
    T value;
    Tuple<Ts...> tail;


    template<size_t idx>
        requires(idx == 0)
    Type<idx, T, Ts...>::type &
    get() noexcept
    {
        return value;
    }


    template<size_t idx>
        requires(idx > 0)
    Type<idx, T, Ts...>::type &
    get() noexcept
    {
        return tail.template get<idx - 1>();
    }
};


int
main()
{
    // std::tuple<int, std::string, double> t{5, "abcd", 4.0};
    // std::println("{}", sizeof(Tuple<int, std::string, double>));
    Tuple<int, std::string, double> t;
    auto &r = t.get<0>();
    r = 4;
    auto &r1 = t.get<1>();
    r1 = "abcd";
    std::println("{} {}", t.get<0>(), t.get<1>());
}
