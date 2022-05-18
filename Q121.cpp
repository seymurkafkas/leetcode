#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int currentMinimum = prices[0];
        int currentMaximum = prices[0];
        int currentMaxProfit = 0;

        for (auto &&price : prices)
        {
            if (price < currentMinimum)
            {
                currentMaxProfit = max(currentMaxProfit, currentMaximum - currentMinimum);

                currentMinimum = price;
                currentMaximum = price;
                continue;
            }

            if (price > currentMaximum)
                currentMaximum = price;
        }

        return max(currentMaxProfit, currentMaximum - currentMinimum);
    }
};

int main(int argc, char **argv)
{

    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;
    std::cout << solution.maxProfit(prices) << "\n";
}