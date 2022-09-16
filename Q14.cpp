#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int longestPrefix = 0;
        int shortestStringLength = INT_MAX;

        for (auto &&elem : strs)
        {
            int currentLength = elem.length();
            shortestStringLength = min(shortestStringLength, currentLength);
        }

        int largestCommonPrefixIndex = 0;

        for (int i = 0; i < shortestStringLength; ++i)
        {
            bool isFirst = true;
            char previous = ' ';

            for (auto &&elem : strs)
            {
                char current = elem[i];
                if (!isFirst && current != previous)
                {
                    largestCommonPrefixIndex = i;
                    goto final;
                }
                isFirst = false;
                previous = current;
            }
        }
        largestCommonPrefixIndex = shortestStringLength;
    final:
        string substring = strs[0].substr(0, largestCommonPrefixIndex);
        return substring;
    }
};

int main(void)
{
    vector<string> input = {"a"};
    Solution solver;
    string result = solver.longestCommonPrefix(input);
    cout << result << '\n';
    return 0;
}