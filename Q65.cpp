#include <string>
#include <iostream>
#include <regex>

class Solution
{
public:
    bool isNumber(std::string s)
    {
        std::regex regex("[+-]?[0-9]*[.]?[0-9]*([eE][0-9]+)?");

        return std::regex_match(s, regex);
    }
};