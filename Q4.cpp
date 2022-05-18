#include <iostream>
#include <vector>

using namespace std;

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

        for (i = 0; i <= median_target_index; ++i)
        {
            if (index_nums1 < size_nums1 && nums1[index_nums1] < nums2[index_nums2])
                ++index_nums1;
            else
                ++index_nums2;
        }

        std::cout << i << "\n";

        return i;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    std::vector<int> first = {0, 1, 4, 5};
    std::vector<int> second = {2, 8, 15};

    solution.findMedianSortedArrays(first, second);
}