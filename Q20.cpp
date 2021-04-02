#include <bits/stdc++.h>

class Solution
{
public:
    bool isValid(string s)
    {

        std::stack<char> pushdownAutomaton;
        for (const auto &currentChar : s)
        {
            if (s == '(' || s == '{' || s == '[')
            {
                pushdownAutomaton.push(s);
            }
            else
            {
                if (pushdownAutomaton.empty() || pushdownAutomaton.pop() != oppositeBracket(currentChar))
                {
                    return false;
                }
            }
        }
        return pushdownAutomaton.empty();
    }
};