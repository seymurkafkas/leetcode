#include <vector>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

struct State
{
    static const char VISITED_INDICATOR = '#';
    vector<vector<char>> *board;
    int index;
    string *word;
    pair<int, int> position;

    State(vector<vector<char>> *_board, string *_word, pair<int, int> _position) : board(_board), index(0), word(_word), position(_position) {}

    State(State &prev_state, pair<int, int> offset) : word(prev_state.word)
    {
        board = prev_state.board;
        index = prev_state.index + 1;
        position.first = prev_state.position.first + offset.first;
        position.second = prev_state.position.second + offset.second;
    }

    bool is_solution_state()
    {
        bool is_final_index = index == (int)word->length() - 1;
        bool does_letter_match = (*word)[index] == (*board)[position.first][position.second];
        return is_final_index && does_letter_match;
    }

    bool is_valid_state()
    {
        bool does_letter_match = (*word)[index] == (*board)[position.first][position.second];
        return does_letter_match;
    }

    bool is_offset_invalid(std::pair<int, int> offset)
    {
        int candidate_row = position.first + offset.first;
        int candidate_column = position.second + offset.second;

        bool is_row_out_of_bounds = candidate_row < 0 || candidate_row >= (int)board->size();
        if (is_row_out_of_bounds)
            return true;

        bool is_column_out_of_bounds = candidate_column < 0 || candidate_column >= (int)board[candidate_row].size();
        if (is_column_out_of_bounds)
            return true;

        return false;
    }

    State get_next_state(pair<int, int> offset)
    {
        return State(*this, offset);
    }

    char mark_current_as_visited()
    {
        char current_value = (*board)[position.first][position.second];
        (*board)[position.first][position.second] = State::VISITED_INDICATOR;
        return current_value;
    }

    void unmark_current_as_visited(char previous_value)
    {
        (*board)[position.first][position.second] = previous_value;
    }

    bool is_visited()
    {
        return (*board)[position.first][position.second] == VISITED_INDICATOR;
    }
};

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        initialize();

        for (int row = 0; row < (int)board.size(); row++)
        {
            for (int column = 0; column < (int)board[row].size(); column++)
            {
                auto position = make_pair(row, column);
                State candidate_start_state(&board, &word, position);

                if (backtrack_and_search(&candidate_start_state))
                    return true;
            }
        }
        return false;
    }

private:
    void initialize()
    {
        m_search_offsets = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    }

    bool backtrack_and_search(State *state)
    {
        if (state->is_visited() || !state->is_valid_state())
            return false;

        if (state->is_solution_state())
            return true;

        char current_character = state->mark_current_as_visited();

        for (auto &&offset : m_search_offsets)
        {
            if (state->is_offset_invalid(offset))
                continue;

            State next_state = state->get_next_state(offset);
            bool is_solution_found = backtrack_and_search(&next_state);

            if (is_solution_found)
                return true;
        }

        state->unmark_current_as_visited(current_character);
        return false;
    }

    vector<pair<int, int>> m_search_offsets;
};

int main(void)
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution solver;
    bool result = solver.exist(board, "ABCB");
    cout << result;
}