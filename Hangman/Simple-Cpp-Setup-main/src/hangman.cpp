#include "hangman.h"
#include <string>
const char* pick_a_random_word()
{
    std::array<std::string, 4> words = {
        "code",
        "crous",
        "imac",
        "opengl",
    };
    return "";

    // TODO: return a random element from the array
}

/// Blocks until the user inputs something of type T in the console, and then returns it
template<typename T>
T get_input_from_user()
{
    // TODO: replace int with T
}