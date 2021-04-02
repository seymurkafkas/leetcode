#include <bits/stdc++.h>

char oppositeBracket(char enclosingBracket)
{

    char res;

    switch (enclosingBracket)
    {

    case ']':
        res = '[';
        break;
    case '}':
        res = '{';
        break;
    case ')':
        res = '(';
        break;
    }
    return res;
}
class Solution
{
public:
    bool isValid(string s)
    {

        std::stack<char> pushdownAutomaton;
        for (const auto &currentChar : s)
        {
            if (currentChar == '(' || currentChar == '{' || currentChar == '[')
            {
                pushdownAutomaton.push(currentChar);
            }
            else
            {
                if (pushdownAutomaton.empty() || pushdownAutomaton.top() != oppositeBracket(currentChar))
                {
                    return false;
                }
                else
                {
                    pushdownAutomaton.pop();
                }
            }
        }
        return pushdownAutomaton.empty();
    }
};