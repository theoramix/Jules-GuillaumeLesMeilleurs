#include "play_guess_the_number.hpp"

/// Returns a random int between min (included) and max (included)
int rand(int min, int max)
{
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}

int get_int_from_user()
{
    int int_user;
    std::cin >> int_user;
    return int_user;
}

void play_guess_the_number()
{
    int  chosen_int = rand(0, 100);
    int  int_user;
    bool finished = false;
    while (!finished) {
        int_user = get_int_from_user();
        if (int_user == chosen_int) {
            finished = true;
        }
        else {
            if (chosen_int > int_user) {
                std::cout << "Greater" << std::endl;
            }
            else {
                std::cout << "Smaller" << std::endl;
            }
        }
    }
}