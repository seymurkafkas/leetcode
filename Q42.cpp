
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {

        int left_index = 0;
        int right_index = height.size() - 1;
        int current_minimum = 0;
        int last_peak_height = 0;
        int partial_water_volume = 0;
        bool removed_volume_right = false, removed_volume_left = false;

        while (left_index < right_index)
        {
            int left_height = height[left_index];
            int right_height = height[right_index];

            current_minimum = min(left_height, right_height);

            if (!removed_volume_left)
            {
                partial_water_volume -= min(left_height, last_peak_height);
                removed_volume_left = true;
            }
            if (!removed_volume_right)
            {
                partial_water_volume -= min(right_height, last_peak_height);
                removed_volume_right = true;
            }

            if (current_minimum > last_peak_height)
            {
                int delta_height = current_minimum - last_peak_height;
                int current_partial_sum = delta_height * (right_index - left_index - 1);
                partial_water_volume += current_partial_sum;
                last_peak_height = current_minimum;
            }

            if (current_minimum == left_height)
            {
                left_index++;
                removed_volume_left = 0;
            }
            else
            {
                right_index--;
                removed_volume_right = 0;
            }
        }

        return partial_water_volume;
    }
};

int main()
{
    vector<int> input = {4, 2, 0, 3, 2, 5};
    Solution s;
    std::cout << s.trap(input);
    return 0;
}
