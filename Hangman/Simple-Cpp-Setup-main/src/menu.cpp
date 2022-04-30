#include "menu.hpp"
#include "hangman.hpp"
#include "play_guess_the_number.hpp"

bool correct_input(char user_input)
{
    if (user_input != '1' && user_input != '2' && user_input != 'q') {
        return false;
    }
    return true;
}

void game_choice(char user_input)
{
    if (user_input == '1') {
        play_guess_the_number();
    }
    else if (user_input == '2') {
        play_hangman();
    }
}
