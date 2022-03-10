#include <vector>
#include <iostream>

using namespace std;

class Solution
{

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        std::vector<bool> grid_first(9, false), grid_second(9, false), grid_third(9, false);
        std::vector<std::vector<bool>> columnContents(9, std::vector<bool>(9, false));

        for (int row = 0; row < 9; ++row)
        {
            std::vector<bool> currentRowContents(9, false);

            if (row % 3 == 0)
            {
                std::fill(grid_first.begin(), grid_first.end(), false);
                std::fill(grid_second.begin(), grid_second.end(), false);
                std::fill(grid_third.begin(), grid_third.end(), false);
            }

            for (int column = 0; column < 9; ++column)
            {
                char currentCharacter = board[row][column];

                if (currentCharacter == '.')
                    continue;

                int currentCharacterIndex = (int)currentCharacter - '1';

                if (currentRowContents[currentCharacterIndex])
                    return false;

                currentRowContents[currentCharacterIndex] = true;

                int currentGroupNumber = (int)(column / 3);
                std::vector<bool> *currentGroupContentsPtr;

                switch (currentGroupNumber)
                {
                case 0:
                    currentGroupContentsPtr = &grid_first;
                    break;
                case 1:
                    currentGroupContentsPtr = &grid_second;
                    break;
                case 2:
                    currentGroupContentsPtr = &grid_third;
                    break;
                }

                if ((*currentGroupContentsPtr)[currentCharacterIndex])
                    return false;

                (*currentGroupContentsPtr)[currentCharacterIndex] = true;

                if (columnContents[column][currentCharacterIndex])
                    return false;

                columnContents[column][currentCharacterIndex] = true;
            }
        }

        return true;
    }
};

int main()
{

    vector<vector<char>> board{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution solver;
    bool isBoardValid = solver.isValidSudoku(board);
}