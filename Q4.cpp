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
        int index_nums1 = 0, index_nums2 = 0;

        int size_nums1 = nums1.size();
        int size_nums2 = nums2.size();

        int combined_length = size_nums1 + size_nums2;

        bool is_even = combined_length % 2 == 0;
        int median_target_index = (int)(combined_length - 1) / 2;
        int i;

        bool is_upper = false;

        for (i = 0; i < median_target_index; ++i)
        {
            if (index_nums1 < size_nums1 && nums1[index_nums1] < nums2[index_nums2])
                ++index_nums1;
            else
                ++index_nums2;
        }

        is_upper = index_nums1 < size_nums1 && ((index_nums2 > size_nums2) || nums1[index_nums1] < nums2[index_nums2]);
        int current_number = is_upper ? nums1[index_nums1] : nums2[index_nums2];

        if (!is_even)
            return current_number;
        else
        {
            if (index_nums1 < size_nums1 && nums1[index_nums1] < nums2[index_nums2])
                ++index_nums1;
            else
                ++index_nums2;

            is_upper = index_nums1 < size_nums1 && ((index_nums2 > size_nums2) || nums1[index_nums1] < nums2[index_nums2]);
            int next_number = is_upper ? nums1[index_nums1] : nums2[index_nums2];
            return (current_number + next_number) / 2.0;
        }
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    std::vector<int> first = {1,2};
    std::vector<int> second = {3,4};

    std::cout << solution.findMedianSortedArrays(first, second);
}