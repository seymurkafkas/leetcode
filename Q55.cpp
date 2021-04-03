#include <vector>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int length = nums.size();

        bool *memo = new bool[length]();
        memo[length - 1] = true;
        for (int i = length - 2; i >= 0; --i)
        {
            if (nums[i] + i > length - 1)
            {
                memo[i] = true;
            }
            else
            {

                for (int k = nums[i]; k > 0; --k)
                {

                    if (memo[k + i])
                    {
                        memo[i] = true;
                        break;
                    }
                }
            }
        }

        return memo[0];
    }
};