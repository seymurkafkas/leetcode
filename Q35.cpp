#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left_index = 0;
        int right_index = nums.size() - 1;
        int center_index;

        while (true)
        {
            if (left_index > right_index)
                break;

            center_index = (left_index + right_index) / 2;

            if (nums[center_index] < target)
            {
                left_index = center_index + 1;
            }
            else if (nums[center_index] > target)
            {
                right_index = center_index - 1;
            }
            else
                return center_index;
        }

        if (nums[center_index] > target)
            return center_index;
        else
            return center_index + 1;
    }
};