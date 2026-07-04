#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int idx, vector<int> &nums, vector<vector<int>> &ans,
               vector<int> output)
    {
        // base case
        if (idx >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        // exclude
        solve(idx + 1, nums, ans, output);

        // include
        int ele = nums[idx];
        output.push_back(ele);
        solve(idx + 1, nums, ans, output);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(index, nums, ans, output);
        return ans;
    }
};

// Time Complexity: O(2^n) where n is the number of elements in the input array. This is because for each element, we have two choices: either to include it in the current subset or to exclude it. Therefore, the total number of subsets generated will be 2^n.
// Space Complexity: O(n) for the recursion stack and O(2^n) for storing all the subsets in the answer vector. The recursion stack can go as deep as n in the worst case, and we need to store all possible subsets, which is 2^n.