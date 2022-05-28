#include <iostream>
#include <stack>
#include <string>
#include <utility>

using namespace std;

typedef pair<int, int> PartialSolution;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        std::stack<int> pushdown_memory;
        std::stack<PartialSolution> partial_solutions;
        int max_length = 0;

        for (unsigned int i = 0; i < s.length(); ++i)
        {
            auto current_element = s[i];

            if (current_element == '(')
                pushdown_memory.emplace(i);
            else if (current_element == ')' && !pushdown_memory.empty())
            {
                int left_paranthesis_index = pushdown_memory.top();
                int size_of_current_match = i - left_paranthesis_index + 1;
                pushdown_memory.pop();

                if (!partial_solutions.empty())
                {
                    auto last_solution = partial_solutions.top();

                    if (last_solution.second > left_paranthesis_index)
                    {
                        partial_solutions.pop();

                        if (!partial_solutions.empty())
                            last_solution = partial_solutions.top();
                    }

                    if (last_solution.second == left_paranthesis_index - 1)
                    {
                        size_of_current_match += last_solution.first;
                        partial_solutions.pop();
                    }
                }

                auto new_partial_solution = std::make_pair(size_of_current_match, i);
                max_length = max(max_length, size_of_current_match);
                partial_solutions.emplace(new_partial_solution);
            }
            else
                partial_solutions = std::move(std::stack<PartialSolution>());
        }

        return max_length;
    }
};

int main()
{
    std::string input = "(()())";
    Solution a;
    std::cout << a.longestValidParentheses(input);
    return 0;
}
