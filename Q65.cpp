#include <string>
#include <iostream>
#include <regex>

class Solution
{
public:
    bool isNumber(std::string s)
    {
        if (s == ".")
        {
            return false;
        }
        std::regex regex("[+-]?(([0-9]+[.]?[0-9]*)|([0-9]*[.]?[0-9]+))([eE][+-]?[0-9]+)?");

        return std::regex_match(s, regex);
    }
};

int main()
{

    Solution solver;
    std::cout << solver.isNumber("-324.e123");

    return 0;
}