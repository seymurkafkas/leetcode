#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        std::vector<int> result_sum;
        int carry = 1;

        for (auto it = digits.rbegin(); it != digits.rend(); ++it)
        {
            int digit = *it;
            int partial_sum = carry + digit;
            int result_digit = partial_sum % 10;
            result_sum.emplace_back(result_digit);
            carry = int(partial_sum / 10);
        }

        if (carry == 1)
            result_sum.emplace_back(1);

        std::reverse(result_sum.begin(), result_sum.end());
        return result_sum;
    }
};
