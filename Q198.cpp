#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        std::vector<int> dp(nums.size(), -1);
        int max_robbery_amount = m_rob_memoized(nums, 0, dp);
        return max_robbery_amount;
    }

private:
    int m_rob_memoized(vector<int> &nums, int index, vector<int> &dp)
    {
        if (index >= nums.size())
            return 0;

        int memoized_solution = dp[index];
        if (memoized_solution != -1)
            return memoized_solution;

        int m_rob_current_included = nums[index] + m_rob_memoized(nums, index + 2, dp);
        int m_rob_current_excluded = m_rob_memoized(nums, index + 1, dp);
        int m_rob = std::max(m_rob_current_included, m_rob_current_excluded);
        dp[index] = m_rob;
        return m_rob;
    }
};

int main(void)
{
    Solution solver;

    return 0;
}