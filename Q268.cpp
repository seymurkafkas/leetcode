#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int vector_size = nums.size();
        int sum = vector_size * (vector_size + 1) / 2;

        for (auto &&elem : nums)
            sum -= elem;

        return sum;
    }
};

int main()
{
    std::vector<int> numbers = {1, 2, 3};
    return 0;
}