#include <string>
#include <iostream>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {

        for (int i = 0; i < s.length(); ++i)
        {
            std::cout << s[i];
        }
        return 0;
    }
};

int main()
{
    Solution a;
    a.lengthOfLongestSubstring("hellothere");
    return 0;
}