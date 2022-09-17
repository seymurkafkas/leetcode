#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagram_map;
        vector<vector<string>> anagrams;

        for (auto &&str : strs)
        {
            string sorted_str = str;
            std::sort(sorted_str.begin(), sorted_str.end());
            vector<string> &anagram = anagram_map[sorted_str];
            anagram.emplace_back(str);
        }

        for (auto &&anagram : anagram_map)
        {
            anagrams.emplace_back(std::move(anagram.second));
        }

        return anagrams;
    }
};


int main(void) {




}