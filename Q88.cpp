#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int nums1_index = m - 1, nums2_index = n - 1;

        for (int i = m + n - 1; i >= 0; --i)
        {
            if (nums2_index < 0)
                return;

            if (nums1_index < 0)
            {
                nums1[i] = nums2[nums2_index];
                nums2_index--;
                continue;
            }

            int nums1_value = nums1[nums1_index];
            int nums2_value = nums2[nums2_index];

            bool is_next_from_nums1 = nums1_value >= nums2_value;

            if (is_next_from_nums1)
            {
                nums1_index--;
                nums1[i] = nums1_value;
            }
            else
            {
                nums1[i] = nums2_value;
                nums2_index--;
            }
        }
    }
};
