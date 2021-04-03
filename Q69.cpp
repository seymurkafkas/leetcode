#include <iostream>

class Solution
{
public:
    int mySqrt(int x)
    {

        if (x == 0 || x == 1)
        {
            return x;
        }

        long long int currentLowerBound = 1;
        long long int currentUpperBound = x;
        long long int currentAnswer, median;

        while (currentLowerBound <= currentUpperBound)
        {

            median = currentLowerBound + (currentUpperBound - currentLowerBound) / 2;

            if (median * median == x)
            {
                currentAnswer = median;
                break;
            }

            else if (median * median - x < 0)
            {
                currentLowerBound = median + 1;
                currentAnswer = median;
            }

            else
            {
                currentUpperBound = median - 1;
            }
        }

        return currentAnswer;
    }
}

;

int main()
{

    Solution solver;
    std::cout << solver.mySqrt(2147395599);

    return 0;
}