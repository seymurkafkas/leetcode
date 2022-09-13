#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int current_maximum = INT_MIN;
        int current_sum = 0;

        for (auto &&element : nums)
        {
            current_sum += element;
            current_maximum = max(current_sum, current_maximum);

            if (current_sum <= 0)
                current_sum = 0;
        }

        return current_maximum;
    }
};

int main(void)
{
    Solution solver;
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int total_sum = solver.maxSubArray(nums);
    std::cout << total_sum << '\n';
    return 0;
}