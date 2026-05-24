#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> m;

        for (auto s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }

        vector<vector<string>> res;

        for (auto it : m)
        {
            res.push_back(it.second);
        }

        return res;
    }
};

// Time Complexity: O(n * k log k) where n is the number of strings and k is the maximum length of a string
// Space Complexity: O(n * k) where n is the number of strings and k is