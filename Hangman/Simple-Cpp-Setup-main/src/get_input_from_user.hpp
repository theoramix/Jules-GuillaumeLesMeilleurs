#pragma once
#include <iostream>

template<typename T>
T get_input_from_user()
{
    T user_value;
    std::cin >> user_value;
    return user_value;
}
