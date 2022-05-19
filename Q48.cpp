#include <vector>
#include <iostream>

namespace util
{

    enum Direction
    {
        RIGHT = 0,
        DOWN = 1,
        LEFT = 2,
        UP = 3,
        END_BOUNDARY = 4,
    };

    Direction &operator++(Direction &input)
    {
        input = (Direction)(input + 1);
        return input;
    }

    struct Indices
    {
        int x, y;

        Indices(int x, int y) : x(x), y(y) {}
    };

    Indices get_rotated_indices(Indices pose, int current_outer_loop_index, int grid_size, Direction direction)
    {
        int d_x, d_y;
        int x, y;

        int manhattan_distance_to_next = grid_size - 1 - 2 * current_outer_loop_index;

        switch (direction)
        {
        case UP:
            y = current_outer_loop_index;
            d_x = manhattan_distance_to_next - (pose.y - y);
            x = pose.x + d_x;
            break;
        case DOWN:
            y = grid_size - current_outer_loop_index - 1;
            d_x = -(manhattan_distance_to_next - (y - pose.y));
            x = pose.x + d_x;
            break;
        case LEFT:
            x = current_outer_loop_index;
            d_y = -(manhattan_distance_to_next - (pose.x - x));
            y = pose.y + d_y;
            break;
        case RIGHT:
            x = grid_size - current_outer_loop_index - 1;
            d_y = (manhattan_distance_to_next - (x - pose.x));
            y = pose.y + d_y;
            break;
        default:
            break;
        }

        std::cout << "Indices :" << x << ", " << y << "\n";
        return Indices(x, y);
    }
}

using namespace std;
using namespace util;

class Solution
{

public:
    void rotate(vector<vector<int>> &matrix)
    {
        int matrix_size = matrix.size();
        int outer_loop_count = (int)(matrix_size / 2);

        for (int i = 0; i < outer_loop_count; ++i)
        {

            int inner_loop_count = matrix_size - 1 - 2 * i;
            int manhattan_distance_to_next = inner_loop_count;

            int current;
            int temp;

            for (int j = 0; j < inner_loop_count; ++j)
            {

                int y_index = i;
                int x_index = i + j;
                current = matrix[y_index][x_index];

                for (Direction direction = RIGHT; direction != END_BOUNDARY; ++direction)
                {
                    Indices next = get_rotated_indices(Indices(x_index, y_index), i, matrix_size, direction);
                    temp = matrix[next.y][next.x];
                    matrix[next.y][next.x] = current;

                    current = temp;
                    y_index = next.y;
                    x_index = next.x;
                }
            }
        }
    }
};

void print_matrix(vector<vector<int>> &matrix)
{
    for (auto &&row : matrix)
    {
        for (auto &&value : row)
            std::cout << value << " , ";

        std::cout << '\n';
    }
}

int main(int argc, char **argv)
{

    std::vector<std::vector<int>> matrix = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    Solution solution;
    solution.rotate(matrix);
    print_matrix(matrix);
    return 0;
}