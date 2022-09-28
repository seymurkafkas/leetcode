#include <string>
#include <unordered_map>
#include <iostream>
#include <istream>
#include <sstream>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        std::unordered_map<char, string> pairings;
        std::unordered_map<string, char> pairings_reverse;

        std::stringstream s_stream(s);
        int pattern_length = pattern.length();
        std::string current_word;
        int pattern_index = 0;

        while (s_stream >> current_word)
        {
            if (pattern_index > pattern_length)
                return false;

            char current_letter = pattern[pattern_index];
            bool is_letter_present = pairings.find(current_letter) != pairings.end();
            bool is_word_present = pairings_reverse.find(current_word) != pairings_reverse.end();

            if (is_letter_present ^ is_word_present)
                return false;
            else if (is_letter_present && is_word_present)
            {
                if (pairings[current_letter] != current_word || pairings_reverse[current_word] != current_letter)
                    return false;
            }
            else
            {
                pairings_reverse[current_word] = current_letter;
                pairings[current_letter] = current_word;
            }

            pattern_index++;
        }

        bool is_matching = pattern_index == pattern_length ? true : false;
        return is_matching;
    }
};

int main(void)
{
    Solution solver;
    std::string input("dog dog dog dog");
    std::string pattern("abba");
    bool is_matching = solver.wordPattern(pattern, input);
    std::cout << is_matching << std::endl;
    return 0;
}