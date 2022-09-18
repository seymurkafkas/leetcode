#include <string>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        initialize_solver(s);
        int initial_index = 0;
        int num_decodings = memoized_get_decoding_count_with_backtrack(initial_index, s);
        return num_decodings;
    }

private:
    static const int s_letter_count = 26;
    vector<int> sub_solutions;

    void initialize_solver(string &str)
    {
        sub_solutions = vector<int>(str.length() + 1, -1);
    }

    int memoized_get_decoding_count_with_backtrack(unsigned int str_index, string &str)
    {
        int solution = sub_solutions[str_index];
        bool is_solution_in_memory = solution != -1;

        if (!is_solution_in_memory)
        {
            solution = get_decoding_count_with_backtrack_dfs(str_index, str);
            sub_solutions[str_index] = solution;
        }

        return solution;
    }

    int get_decoding_count_with_backtrack_dfs(unsigned int str_index, string &str)
    {
        if (str_index >= str.length())
            return 1;

        int remaining_char_count = str.length() - str_index;
        int potential_decoding_length = min(2, remaining_char_count);
        int total_decoding_count = 0;

        for (int i = 1; i <= potential_decoding_length; ++i)
        {
            string potential_decoding = str.substr(str_index, i);
            if (is_unit_decoding_valid(potential_decoding))
            {
                int sub_decoding_count = memoized_get_decoding_count_with_backtrack(str_index + i, str);
                total_decoding_count += sub_decoding_count;
            }
        }

        return total_decoding_count;
    }

    bool is_unit_decoding_valid(string &decoding)
    {
        if (decoding[0] == '0')
            return false;

        if (decoding.length() >= 2)
        {
            int tens = decoding[0];
            int ones = decoding[1];
            int decoding = (tens - '0') * 10 + (ones - '0');
            return decoding <= s_letter_count;
        }

        return true;
    }
};

int main(void)
{
    string input("1");
    Solution solver;
    int decodings = solver.numDecodings(input);
    cout << decodings << '\n';
    return 0;
}