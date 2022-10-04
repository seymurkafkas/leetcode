#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int s_index = 0, t_index = 0;
        int s_length = s.length();
        int t_length = t.length();

        while (true)
        {
            char s_elem = s[s_index];
            char t_elem = t[t_index];

            if (s_elem == t_elem)
                s_index++;

            t_index++;

            if (s_index >= s_length)
                return true;

            if (t_index >= t_length)
                return false;
        }

        return false;
    }
};

int main(void)
{
    std::string a("abc");
    std::string b("ahbgdc");
    Solution solver;
    std::cout << solver.isSubsequence(a, b);
    return 0;
}