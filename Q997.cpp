#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        std::vector<bool> candidate_judges(n, true);
        std::vector<int> trustee_count(n, 0);

        for (auto &&trust_pair : trust)
        {
            int truster = trust_pair[0];
            int trustee = trust_pair[1];
            trustee_count[trustee - 1] += 1;
            candidate_judges[truster - 1] = false;
        }

        int solution_count = 0;
        int solution_label;

        for (int i = 0; i < n; ++i)
        {
            if (candidate_judges[i] && trustee_count[i] == n - 1)
            {
                solution_count++;
                solution_label = i + 1;
            }
        }

        return solution_count == 1 ? solution_label : -1;
    }
};
