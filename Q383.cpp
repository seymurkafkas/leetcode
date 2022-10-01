#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        auto frequency_map = get_frequency_map(magazine);
        for (auto &&character : ransomNote)
        {
            int count_remaining_in_magazine = frequency_map[character];
            if (count_remaining_in_magazine <= 0)
                return false;
            frequency_map[character] = count_remaining_in_magazine - 1;
        }
        return true;
    }

private:
    std::unordered_map<char, unsigned int> get_frequency_map(std::string &sentence)
    {
        std::unordered_map<char, unsigned int> frequency_map;
        for (auto &&character : sentence)
            frequency_map[character] += 1;
        return frequency_map;
    }
};

int main(void)
{
    std::string input("aa");
    std::string magazine("aab");
    Solution solver;
    std::cout << solver.canConstruct(input, magazine) << '\n';
}