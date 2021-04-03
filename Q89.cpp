#include <iostream>
#include <vector>
#include <math.h>

class Solution
{
public:
    std::vector<int> grayCode(int n)
    {

        std::vector<int> grayCodeVector;
        grayCodeVector.push_back(0);
        for (int i = 1; i < 1 << n; ++i)
        {

            grayCodeVector.push_back(grayCodeVector[i - 1] ^ getXOROperand(i));
        }

        return grayCodeVector;
    }

    int getXOROperand(int currentVectorIndex)
    {

        int currentDivisor = 2;
        for (int potentialBitIndex = 1; potentialBitIndex <= 16; potentialBitIndex++)
        {

            if (currentVectorIndex % currentDivisor == (currentDivisor) / 2)
            {
                return currentDivisor / 2;
            }
            else
            {
                currentDivisor *= 2;
            }
        }
        return 0;
    }
};

int main()
{

    Solution solver;
    std::cout << solver.getXOROperand(8);

    return 0;
}