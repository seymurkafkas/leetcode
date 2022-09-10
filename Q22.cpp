#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

enum Action
{
    LEFT_BRACKET_PLACE,
    RIGHT_BRACKET_PLACE
};

class SolverState
{
public:
    static SolverState make_initial_state(int total_bracket_count)
    {
        auto initial_state = SolverState(total_bracket_count);
        return initial_state;
    }

    SolverState(SolverState &from_state, Action action_taken)
    {
        std::string &previous_partial_string = from_state.partial_string;
        char emplaced_character;

        if (action_taken == LEFT_BRACKET_PLACE)
        {
            emplaced_character = '(';
            placed_left_bracket_count = from_state.placed_left_bracket_count + 1;
            remaining_left_bracket_count = from_state.remaining_left_bracket_count - 1;
            remaining_right_bracket_count = from_state.remaining_right_bracket_count;
            placed_right_bracket_count = from_state.placed_right_bracket_count;
        }
        else if (action_taken == RIGHT_BRACKET_PLACE)
        {
            emplaced_character = ')';
            placed_right_bracket_count = from_state.placed_right_bracket_count + 1;
            remaining_right_bracket_count = from_state.remaining_right_bracket_count - 1;
            remaining_left_bracket_count = from_state.remaining_left_bracket_count;
            placed_left_bracket_count = from_state.placed_left_bracket_count;
        }

        partial_string = previous_partial_string + emplaced_character;
    }

    bool is_invalid()
    {
        bool unmatched_right_bracket_exists = (placed_right_bracket_count - placed_left_bracket_count) > 0;
        return unmatched_right_bracket_exists;
    }

    std::vector<Action> get_available_actions()
    {
        std::vector<Action> available_actions;

        if (remaining_left_bracket_count > 0)
            available_actions.emplace_back(LEFT_BRACKET_PLACE);

        if (remaining_right_bracket_count > 0)
            available_actions.emplace_back(RIGHT_BRACKET_PLACE);

        return available_actions;
    }

    bool is_complete()
    {
        bool no_leftover_left_bracket = remaining_left_bracket_count == 0;
        bool no_leftover_right_bracket = remaining_right_bracket_count == 0;
        return no_leftover_left_bracket && no_leftover_right_bracket;
    }

    std::string get_partial_string()
    {
        return partial_string;
    }

private:
    int remaining_left_bracket_count;
    int remaining_right_bracket_count;
    int placed_left_bracket_count;
    int placed_right_bracket_count;
    std::string partial_string;
    SolverState(int bracket_count) : remaining_left_bracket_count(bracket_count),
                                     remaining_right_bracket_count(bracket_count),
                                     placed_left_bracket_count(0),
                                     placed_right_bracket_count(0)
    {
    }
};

class Solution
{
private:
    void add_or_backtrack(SolverState &state, std::vector<string> &solutions)
    {
        bool is_state_invalid = state.is_invalid();
        if (is_state_invalid)
            return;

        bool is_state_final = state.is_complete();
        if (is_state_final)
            solutions.emplace_back(state.get_partial_string());

        auto available_actions = state.get_available_actions();
        for (auto &&action : available_actions)
        {
            SolverState next_state = SolverState(state, action);
            add_or_backtrack(next_state, solutions);
        }
    }

public:
    Solution()
    {
    }

    vector<string> generateParenthesis(int n)
    {
        SolverState initial_state = SolverState::make_initial_state(n);
        std::vector<string> solutions;
        add_or_backtrack(initial_state, solutions);
        return solutions;
    }
};

void print_solutions(std::vector<string> &solution_vector)
{
    for (auto &&expression : solution_vector)
        cout << expression << '\n';
}

int main(int argc, char **argv)
{
    int input;
    cin >> input;
    Solution solver;
    vector<string> result = solver.generateParenthesis(input);
    print_solutions(result);
}