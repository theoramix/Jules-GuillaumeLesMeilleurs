#include <iostream>
#include "menu.hpp"

int main()
{
    std::cout << "Welcome! What game would you like to play?" << std::endl;
    std::cout << "1: Play Guess the Number" << std::endl;
    std::cout << "2: Play Hangman" << std::endl;
    std::cout << "q: Quit" << std::endl;
    char user_input;
    std::cin >> user_input;
    while (!correct_input(user_input)) {
        std::cout << "Sorry I don't know that command! Try again please." << std::endl;
        std::cin >> user_input;
    }
    game_choice(user_input);
}
