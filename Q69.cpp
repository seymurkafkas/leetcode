#include <iostream>

class Solution
{
public:
    int mySqrt(int x)
    {

        float guess = x / 2.0;
        while (guess * guess - x >= 1 || guess * guess < x)
        {

            guess = (guess + x / guess) / 2;
        }
        return (int)guess;
    }
};

int main()
{

    Solution solver;
    std::cout << solver.mySqrt(1);

    return 0;
}