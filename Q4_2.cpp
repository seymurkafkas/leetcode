#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size_nums1 = nums1.size();
        int size_nums2 = nums2.size();
        int index_left = 0, index_right = 0;
        int total_length = size_nums1 + size_nums2;
        bool is_even = total_length % 2 == 0;
        int delta_to_median_index = (int)((total_length - 1) / 2);
        double result;

        while (delta_to_median_index > 0)
        {
            int items_left_left = size_nums1 - index_left;
            int items_left_right = size_nums2 - index_right;
            int move_larger_array_by = delta_to_median_index - min(items_left_left, items_left_right);

            if (move_larger_array_by > 0)
            {
                if (items_left_left > items_left_right)
                    index_left += move_larger_array_by;
                else
                    index_right += move_larger_array_by;

                delta_to_median_index -= move_larger_array_by;
            }

            if (delta_to_median_index == 0)
                break;

            int delta_check_index = (delta_to_median_index - 1) / 2;

            if (nums1[index_left + delta_check_index] <= nums2[index_right + delta_check_index])
                index_left += (delta_check_index + 1);
            else
                index_right += (delta_check_index + 1);

            delta_to_median_index -= (delta_check_index + 1);
        }

        if (index_left < size_nums1 && (index_right >= size_nums2 || nums1[index_left] <= nums2[index_right]))
        {
            result = nums1[index_left];
            index_left++;
        }
        else
        {
            result = nums2[index_right];
            index_right++;
        }

        if (is_even)
        {
            int higher_median;

            if (index_left < size_nums1 && (index_right >= size_nums2 || nums1[index_left] <= nums2[index_right]))
                higher_median = nums1[index_left];
            else
                higher_median = nums2[index_right];

            result = (result + higher_median) * 0.5;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    std::vector<int> first = {};
    std::vector<int> second = {1, 2, 3, 4};
    std::cout << solution.findMedianSortedArrays(first, second);
}