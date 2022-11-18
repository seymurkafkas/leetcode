#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    /// @brief Return all permutations of the input vector of integers
    /// Assumes the input vector is sorted in an ascending order.
    /// @param nums A vector containing candidate (possibly duplicate) numbers
    /// @return All unique permutations of nums (without replacement)
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int nums_length = nums.size();
        vector<vector<int>> result;
        build_recursively(nums, 0, result);
        return result;
    }

private:
    void build_recursively(vector<int> &nums, int boundary_idx, vector<vector<int>> &result)
    {
        int nums_size = nums.size();

        if (boundary_idx == nums_size - 1)
        {
            result.emplace_back(nums);
            return;
        }

        std::vector<int> nums_with_boundary_assigned = nums;

        for (int i = boundary_idx; i < nums_size; i++)
        {
            if (i != boundary_idx && nums[i] == nums[i - 1])
                continue;

            swap(nums_with_boundary_assigned[boundary_idx], nums_with_boundary_assigned[i]);
            build_recursively(nums_with_boundary_assigned, boundary_idx + 1, result);
        }
    }
};

int main(void)
{
    std::vector<int> nums = {1, 1, 2};
    Solution solver;
    auto &&permutations = solver.permuteUnique(nums);

    for (auto &&permutation : permutations)
    {
        for (auto &elem : permutation)
            std::cout << elem << ' ';

        std::cout << '\n';
    }

    return 0;
}