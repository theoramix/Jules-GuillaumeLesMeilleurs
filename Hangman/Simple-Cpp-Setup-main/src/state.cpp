#include "state.hpp"
#include <assert.h>
#include <algorithm>
#include <iostream>

void IncompleteWord::show_word_to_guess_with_missing_letters()
{
    for (size_t index = 0; index < _word.size(); index++) {
        if (_letters_revealed[index] == true) {
            std::cout << _word[index];
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

bool IncompleteWord::word_contains(char letter)
{
    if (_word.find(letter) != std::string::npos) {
        return true;
    }
    return false;
}

void IncompleteWord::mark_as_guessed(char guessed_letter)
{
    std::transform(_letters_revealed.begin(), _letters_revealed.end(), _word.begin(), _letters_revealed.begin(), [&](bool b, char letter) {
        if (guessed_letter == letter) {
            return true;
        }
        else {
            return b;
        }
    });
}

void show_number_of_lives(int number_of_lives)
{
    if (number_of_lives == 1) {
        std::cout << "Last chance pal!" << std::endl;
    }
    else if (number_of_lives <= 3) {
        std::cout << "Careful now, you only have " << number_of_lives << " lives left!" << std::endl;
    }
    else {
        std::cout << "You still have " << number_of_lives << " lives left!" << std::endl;
    }
}

bool player_is_alive(int number_of_lives)
{
    if (number_of_lives == 0) {
        return false;
    }
    else
        return true;
}

bool player_has_won(const std::vector<bool>& letters_guessed)
{
    //find renvoie l'itérateur de la dernière valeur du vecteur si il ne trouve pas false
    const bool alllettersfound = std::find(letters_guessed.begin(), letters_guessed.end(), false) == letters_guessed.end();
    return alllettersfound;
}

/*
void show_word_to_guess_with_missing_letters(const std::string& word, const std::vector<bool>& letters_guessed)
{
    size_t size_word = letters_guessed.size();
    for (size_t index = 0; index < size_word; index++) {
        if (letters_guessed[index] == true) {
            std::cout << word[index];
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}


bool word_contains(char letter, std::string_view word)
{
    if (word.find(letter) != std::string::npos) {
        return true;
    }
    return false;
}

void mark_as_guessed(char guessed_letter, std::vector<bool>& letters_guessed, std::string_view word_to_guess)
{
    assert(word_to_guess.size() == letters_guessed.size());
    std::transform(letters_guessed.begin(), letters_guessed.end(), word_to_guess.begin(), letters_guessed.begin(), [&](bool b, char letter) {
        if (guessed_letter == letter) {
            return true;
        }
        else {
            return b;
        }
    });
}
*/

void remove_one_life(int& lives_count)
{
    lives_count--;
}

void show_congrats_message(std::string_view word_to_guess)
{
    std::cout << "Congratulations superstar! You won!" << std::endl;
    std::cout << "The word was: " << word_to_guess << " (crazy I know!)" << std::endl;
}

void show_defeat_message(std::string_view word_to_guess)
{
    std::cout << "Boo! You lost!" << std::endl;
    std::cout << "The word was: " << word_to_guess << " (it wasn't that hard to find...)" << std::endl;
}
