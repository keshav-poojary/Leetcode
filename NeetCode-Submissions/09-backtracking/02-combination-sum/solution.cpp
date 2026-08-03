#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &candidates, int target,
               int index, vector<int> output)
    {
        if (index >= candidates.size())
        {
            return;
        }

        if (target == 0)
        {
            ans.push_back(output);
            return;
        }

        // include
        if (candidates[index] <= target)
        {
            output.push_back(candidates[index]);
            solve(ans, candidates, target - candidates[index], index, output); // no index + 1 because we can reuse same elements
            output.pop_back();                                                 // IMPPPP
        }

        // exclude
        solve(ans, candidates, target, index + 1, output);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(ans, candidates, target, index, output);
        return ans;
    }
};

// Time Complexity: O(2^t) where t is the target value. In the worst case, we may have to explore all possible combinations of candidates to reach the target value. This can lead to an exponential number of recursive calls, resulting in a time complexity of O(2^t).
// Space Complexity: O(t) for the recursion stack and O(k) for storing the current