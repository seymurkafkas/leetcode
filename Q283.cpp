#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int zero_count = 0;
        int nums_length = nums.size();
        for (int i = 0; i < nums_length; ++i)
        {
            int current_value = nums[i];
            if (current_value == 0)
                zero_count++;
            else
                nums[i - zero_count] = current_value;
        }

        for (int i = nums_length - 1; i >= nums_length - zero_count; --i)
            nums[i] = 0;
    }
};

int main(void)
{
    vector<int> input = {0};
    Solution solver;
    solver.moveZeroes(input);

    for (auto &&elem : input)
        cout << elem << endl;

    return 0;
}