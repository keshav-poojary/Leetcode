#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<int>> &res, vector<int> &ds, vector<bool> &vis,
               int n, vector<int> &nums)
    {
        if (ds.size() == n)
        {
            res.push_back(ds);
            return;
        }

        // iterate through each ele
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ds.push_back(nums[i]);
                vis[i] = true;
                solve(res, ds, vis, n, nums);
                ds.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> ds;
        vector<bool> vis(n, false);
        solve(res, ds, vis, n, nums);
        return res;
    }
};

// time complecity -> o(n*n!) where n is the number of elements in the input array. The reason for this is that we are generating all possible permutations of the input array, which has a total of n! permutations. For each permutation, we are performing a linear scan to copy the elements into the result vector, which takes O(n) time. Therefore, the overall time complexity is O(n*n!).
// space complexity -> o(n) for the recursion stack and o(n) for the visited array