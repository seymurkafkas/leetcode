#include <vector>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int length = nums.size();

        int leftmostReachingIndex = length - 1;
        for (int i = length - 2; i >= 0; --i)
        {
            if (nums[i] + i >= leftmostReachingIndex)
            {
                leftmostReachingIndex = i;
            }
        }

        return leftmostReachingIndex == 0;
    }
};