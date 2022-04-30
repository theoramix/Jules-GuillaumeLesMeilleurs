#pragma once
#include <string>
#include <vector>

class IncompleteWord {
public:
    IncompleteWord(std::string_view word)
        : _word{word}
        , _letters_revealed(word.size(), false)
    {
    }

    //GETTERS
    std::vector<bool> get_letters_revealed()
    {
        return _letters_revealed;
    }

    std::string get_word()
    {
        return _word;
    }

    void show_word_to_guess_with_missing_letters();

    bool word_contains(char letter);

    void mark_as_guessed(char guessed_letter);

private:
    std::string       _word;
    std::vector<bool> _letters_revealed;
};

void show_number_of_lives(int number_of_lives);

bool player_is_alive(int number_of_lives);

bool player_has_won(const std::vector<bool>& letters_guessed);

//void show_word_to_guess_with_missing_letters(const std::string& word, const std::vector<bool>& letters_guessed);

//bool word_contains(char letter, std::string_view word);

//void mark_as_guessed(char guessed_letter, std::vector<bool>& letters_guessed, std::string_view word_to_guess);

void remove_one_life(int& lives_count);

void show_congrats_message(std::string_view word_to_guess);

void show_defeat_message(std::string_view word_to_guess);
