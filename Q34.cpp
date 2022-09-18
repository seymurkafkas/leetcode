#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int any_occurrence_index = find_any_occurrence_index(nums, 0, nums.size() - 1, target);
        int first_occurrence_index = find_first_occurrence_index(nums, target, any_occurrence_index);
        int last_occurrence_index = find_last_occurrence_index(nums, target, any_occurrence_index);
        vector<int> result = {first_occurrence_index, last_occurrence_index};
        return result;
    }

private:
    int find_first_occurrence_index(vector<int> &nums, int target, int occurrence_index)
    {
        if (occurrence_index == -1)
            return -1;

        int first_occurrence_index = -1;

        for (int i = occurrence_index; i >= 0; --i)
        {
            if (nums[i] == target)
                first_occurrence_index = i;
            else
                break;
        }

        return first_occurrence_index;
    }

    int find_last_occurrence_index(vector<int> &nums, int target, int occurrence_index)
    {
        if (occurrence_index == -1)
            return -1;

        int last_occurrence_index = -1;

        for (int i = occurrence_index; i < (int)nums.size(); ++i)
        {
            if (nums[i] == target)
                last_occurrence_index = i;
            else
                break;
        }

        return last_occurrence_index;
    }

    int find_any_occurrence_index(vector<int> &nums, int lower, int upper, int target)
    {
        if (nums.size() == 0 || lower > upper)
            return -1;

        int mid_index = (int)((lower + upper) / 2);
        int mid_element = nums[mid_index];

        if (mid_element == target)
            return mid_index;

        if (lower == upper)
            return -1;

        if (mid_element > target)
            return find_any_occurrence_index(nums, lower, mid_index - 1, target);
        else
            return find_any_occurrence_index(nums, mid_index + 1, upper, target);

        return -1;
    }
};

int main(void)
{
    Solution solver;
    vector<int> nums = {2, 2};

    auto result_vector = solver.searchRange(nums, 1);
    cout << result_vector[0] << endl
         << result_vector[1] << endl;
}