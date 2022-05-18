#include <vector>
#include <unordered_set>
#include <iostream>
#include <iterator>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::unordered_set<int> hash_set(nums.size());

        for (auto &&elem : nums)
        {
            auto iterator_and_confirmation = hash_set.emplace(elem);

            if (!iterator_and_confirmation.second)
                return true;
        }

        return false;
    }
};

int main(int argc, char **argv)
{

    std::vector<int> nums = {0, 5, 1, 2, 3, 62, 12};
    Solution solution;
    std::cout << solution.containsDuplicate(nums);

    return 0;
}