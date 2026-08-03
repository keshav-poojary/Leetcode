#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int i, vector<vector<int>> &res, vector<int> &output,
               vector<int> &nums)
    {
        // base case
        if (i >= nums.size())
        {
            res.push_back(output);
            return;
        }

        // include
        output.push_back(nums[i]);
        solve(i + 1, res, output, nums);
        output.pop_back();

        // exclue
        solve(i + 1, res, output, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int i = 0;
        vector<vector<int>> res;
        vector<int> output;
        solve(i, res, output, nums);

        for (int i = 0; i < res.size(); i++)
        {
            sort(res[i].begin(), res[i].end());
        }

        set<vector<int>> s;

        for (auto r : res)
        {
            s.insert(r);
        }

        res.clear();

        for (auto data : s)
        {
            res.push_back(data);
        }

        return res;
    }
};

// Same as subset - i just return in sorted order and then use set to remove duplicates. I can also use a map to check if the subset is already present or not. But i used set because it is easier to implement.
