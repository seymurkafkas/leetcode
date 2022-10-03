#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unsigned int s_length = s.length();
        std::unordered_map<char, int> frequency_map;

        if (s_length != t.length())
            return false;

        auto s_frequency_map = build_frequency_map(s);
        bool is_anagram = are_containers_bijections(t, s_frequency_map);
        return is_anagram;
    }

private:
    std::unordered_map<char, int> build_frequency_map(std::string &input)
    {
        std::unordered_map<char, int> frequency_map;

        for (auto &&character : input)
            frequency_map[character] += 1;

        return frequency_map;
    }

    bool are_containers_bijections(std::string &cont_str, std::unordered_map<char, int> &cont_frequency_map)
    {
        for (auto &&character : cont_str)
        {
            int frequency_before_remove = cont_frequency_map[character];
            if (frequency_before_remove <= 0)
                return false;

            cont_frequency_map[character] = frequency_before_remove - 1;
        }

        return true;
    }
};

int main(void)
{

    std::string input("rat");
    std::string t("car");
    Solution solver;
    bool result = solver.isAnagram(input, t);
    std::cout << result << '\n';
}