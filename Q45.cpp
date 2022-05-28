#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int array_size = nums.size();
        std::vector<int> results(array_size, 0);
        int last_index = array_size - 1;

        for (int i = last_index - 1; i >= 0; i--)
        {
            int current_jump_length = nums[i];

            if (current_jump_length >= (last_index - i))
            {
                results[i] = 1;
                continue;
            }

            int current_minimum = INT_MAX;

            for (int j = 1; j <= current_jump_length && (j + i) <= last_index; j++)
            {
                if (results[i + j] == INT_MAX)
                    continue;

                int candidate_jump_count = results[i + j] + 1;
                current_minimum = min(current_minimum, candidate_jump_count);
            }

            results[i] = current_minimum;
        }

        return results[0];
    }
};

int main()
{
    Solution a;
    std::vector<int> numbers = {2, 3, 0, 1, 4};
    std::cout << a.jump(numbers);
    return 0;
}