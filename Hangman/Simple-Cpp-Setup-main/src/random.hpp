#pragma once

#include <random>

//Generate a random element of type T between min & max
template<typename T>
T rand(T min, T max)
{
    static std::default_random_engine generator{std::random_device{}()};
    std::uniform_int_distribution<T>  distribution{min, max};
    return distribution(generator);
}
