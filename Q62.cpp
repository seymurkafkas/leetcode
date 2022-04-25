#include <iostream>
#include <vector>

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<int> currentColumn(m, 1);

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (j == 0)
                    continue;

                currentColumn[j] += currentColumn[j - 1];
            }
        }

        return currentColumn.back();
    }
};

int main(int argc, char **argv)
{
    Solution a;
    std::cout << a.uniquePaths(3, 2);
    return 0;
}