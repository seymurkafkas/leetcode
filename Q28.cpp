#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int haystack_length = haystack.length();
        int needle_length = needle.length();
        for (int i = 0; i < haystack_length; ++i)
        {
            bool is_matching = false;
            bool has_reached_end = false;
            for (int j = 0; j < needle_length; ++j)
            {
                bool is_out_of_bounds = i + j >= haystack_length;
                if (is_out_of_bounds)
                {
                    has_reached_end = true;
                    break;
                }

                is_matching = needle[j] == haystack[i + j];
                if (!is_matching)
                    break;
            }

            if (is_matching && !has_reached_end)
                return i;
        }
        return -1;
    }
};

int main(void)
{
    std::string needle("sad");
    std::string haystack("basadbutsad");

    Solution solver;
    int result = solver.strStr(haystack, needle);
    std::cout << result << '\n';
}