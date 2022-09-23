#include <vector>
#include <iostream>

using namespace std;

enum GridState
{
    DEAD_ALIVE = -1,
    DEAD_DEAD = -2,
    ALIVE_DEAD = -3,
    ALIVE_ALIVE = -4
};

class Board
{
public:
    Board(std::vector<vector<int>> &board) : m_board(board) {}

    void transform_board()
    {
        int row_count = m_board.size();
        for (int row = 0; row < row_count; ++row)
        {
            int col_count = m_board[row].size();
            for (int col = 0; col < col_count; ++col)
            {
                int successor_grid_state = get_successor_element(row, col);
                m_board[row][col] = successor_grid_state;
            }
        }
    }

    void post_process_board()
    {
        int row_count = m_board.size();
        for (int row = 0; row < row_count; ++row)
        {
            int col_count = m_board[row].size();
            for (int col = 0; col < col_count; ++col)
            {
                int current_elem = m_board[row][col];
                int transformed_value;

                if (current_elem == ALIVE_ALIVE || current_elem == DEAD_ALIVE)
                    transformed_value = 1;
                else if (current_elem == DEAD_DEAD || ALIVE_DEAD)
                    transformed_value = 0;

                m_board[row][col] = transformed_value;
            }
        }
    }

private:
    vector<vector<int>> &m_board;

    bool is_within_bounds(int row, int column)
    {
        int board_row_count = m_board.size();
        int board_col_count = m_board[0].size(); // TODO: Confirm if true;

        bool row_within_bounds = row < board_row_count && row >= 0;
        bool col_within_bounds = column < board_col_count && column >= 0;
        return row_within_bounds && col_within_bounds;
    }

    bool is_alive(int row, int column)
    {
        int grid_value = m_board[row][column];
        return grid_value == 1 || grid_value == ALIVE_DEAD || grid_value == ALIVE_ALIVE;
    }

    int get_successor_element(int row, int column)
    {
        int d_rows[] = {-1, 0, 1};
        int d_cols[] = {-1, 0, 1};
        int live_count = 0;

        for (auto d_row : d_rows)
        {
            for (auto d_col : d_cols)
            {
                int adjacent_row = row + d_row;
                int adjacent_column = column + d_col;

                if (!is_within_bounds(adjacent_row, adjacent_column) || (d_row == 0 && d_col == 0))
                    continue;

                if (is_alive(adjacent_row, adjacent_column))
                    live_count++;
            }
        }

        GridState next_grid_state;

        if (is_alive(row, column))
            next_grid_state = (live_count == 2 || live_count == 3) ? ALIVE_ALIVE : ALIVE_DEAD;
        else
            next_grid_state = live_count == 3 ? DEAD_ALIVE : DEAD_DEAD;

        return next_grid_state;
    }
};

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        Board game_board(board);
        game_board.transform_board();
        game_board.post_process_board();
    }

private:
};

namespace util
{
    void print_board(vector<vector<int>> &board)
    {
        for (auto &&row : board)
        {
            for (auto &&elem : row)
                cout << elem;
            cout << endl;
        }
    }

};
int main(void)
{
    vector<vector<int>> board = {{1, 1},
                                 {1, 0}};
    Solution solver;
    solver.gameOfLife(board);
    util::print_board(board);
    return 0;
}