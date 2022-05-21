#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {

        int n = grid[0].size();
        int m = grid.size();

        int total_negative_count = 0;
        int current_row_index = 0;

        for (int current_column_index = n - 1; current_column_index >= 0; --current_column_index)
        {
            int current_number = grid[current_row_index][current_column_index];

            while (current_number >= 0)
            {
                current_row_index++;
                if (current_row_index >= m)
                    return total_negative_count;

                current_number = grid[current_row_index][current_column_index];
            }

            total_negative_count += (m - current_row_index);
        }

        return total_negative_count;
    }
};