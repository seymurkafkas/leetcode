#include <string>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, unsigned int> hashMap;
        int currentResult = 0;
        int maxResult = 0;
        for (int i = 0, j = 0; j < s.length(); ++j)
        {
            auto it = hashMap.find(s[j]);
            if (it == hashMap.end() || it->second < i)
            {
                std::cout << "X";
                hashMap[s[j]] = j;
                currentResult++;
            }
            else
            {
                std::cout << "I";
                i = hashMap[s[j]] + 1;
                maxResult = std::max(maxResult, currentResult);
                currentResult = j - i + 1;
            }
        }

        return std::max(maxResult, currentResult);
    }
};

int main()
{
    Solution a;
    std::cout << a.lengthOfLongestSubstring("aaaaaaaba");
    return 0;
}