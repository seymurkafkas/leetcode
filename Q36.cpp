#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        std::unordered_set<char> grid_first, grid_second, grid_third;
        std::vector<std::unordered_set<char>> columnContents;

        for (int row = 0; row < 9; ++row)
        {
            std::unordered_set<char> currentRowContents;

            if (row % 3 == 0)
            {
                grid_first.clear();
                grid_second.clear();
                grid_third.clear();
            }

            for (int column = 0; column < 9; ++column)
            {
                char currentCharacter = board[row][column];
                if (currentCharacter == ',')
                    continue;

                std::unordered_set<char>::const_iterator iteratorToFoundElement = currentRowContents.find(currentCharacter);
                if (iteratorToFoundElement == currentRowContents.end())
                    return false;

                currentRowContents.insert(currentCharacter);

                int currentGroupNumber = (int)(column / 3) * 3;
                const std::unordered_set<char> *currentGroupContentsPtr;

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

                iteratorToFoundElement = currentGroupContentsPtr->find(currentCharacter);

                if (iteratorToFoundElement == currentGroupContentsPtr->end())
                    return false;
            }
        }

        return true;
    }
};