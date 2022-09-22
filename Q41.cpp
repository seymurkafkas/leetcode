#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int nums_size = nums.size();
        for (int i = 0; i < nums_size;)
        {
            int current_value = nums[i];
            if (!_is_num_within_boundary(current_value, 1, nums_size) || nums[current_value - 1] == current_value)
            {
                i++;
                continue;
            }
            _swap_elements(nums, i, current_value - 1);
        }
        int first_missing_positive = _find_first_nonmatching_element(nums);
        return first_missing_positive;
    }

private:
    bool _is_num_within_boundary(int num, int lower_bound, int upper_bound)
    {
        return num >= lower_bound && num <= upper_bound;
    }

    void _swap_elements(vector<int> &nums, int first, int second)
    {
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }

    int _find_first_nonmatching_element(vector<int> &nums)
    {
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i)
        {
            int current_value = nums[i];
            if (current_value != i + 1)
                return i + 1;
        }
        return nums_size + 1;
    }
};

int main(void)
{
    Solution solver;
    vector<int> input = {1, 1};
    int result = solver.firstMissingPositive(input);
    cout << result;
}