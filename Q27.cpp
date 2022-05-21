#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int nums_size = nums.size();
        int displacement_to_desired = 0;

        for (int i = 0; i < nums_size; ++i)
        {
            int current_value = nums[i];

            if (current_value == val)
                displacement_to_desired++;
            else
                nums[i - displacement_to_desired] = current_value;
        }

        int k = nums_size - displacement_to_desired;
        return k;
    }
};