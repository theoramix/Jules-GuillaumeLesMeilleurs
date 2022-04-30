#include "hangman.hpp"
#include <array>
#include <cctype>
#include <string>
#include "get_input_from_user.hpp"
#include "random.hpp"
#include "state.hpp"

const char* pick_a_random_word()
{
    static constexpr std::array<const char*, 5> words = {
        "cool",
        "super",
        "bien",
        "brioche",
        "carotte"};

    int random_number = rand<unsigned long>(0, words.size());
    return words[random_number];
}

void play_hangman()
{
    int number_of_lives = 10;
    //const std::string word_to_guess   = pick_a_random_word();
    IncompleteWord word_to_guess{pick_a_random_word()};
    //std::vector<bool> letters_guessed(word_to_guess.size(), false);
    while (player_is_alive(number_of_lives) && !player_has_won(word_to_guess.get_letters_revealed())) {
        show_number_of_lives(number_of_lives);
        word_to_guess.show_word_to_guess_with_missing_letters();
        //tolower permet de reconnaitre les lettres en majuscule
        const auto guess = std::tolower(get_input_from_user<char>());
        if (word_to_guess.word_contains(guess)) {
            word_to_guess.mark_as_guessed(guess);
        }
        else {
            remove_one_life(number_of_lives);
        }
    }
    if (player_has_won(word_to_guess.get_letters_revealed())) {
        show_congrats_message(word_to_guess.get_word());
    }
    else {
        show_defeat_message(word_to_guess.get_word());
    }
}
