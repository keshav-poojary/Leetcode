#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, vector<int> &s, vector<int> &dp)
    {
        // Base case - when i is greater than or equal to the size of the stoneValue array, return 0 as there are no stones left to take.
        if (i >= s.size())
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int res = INT_MIN;

        res = s[i] - solve(i + 1, s, dp);
        if (i + 1 < s.size())
            res = max(res, s[i] + s[i + 1] - solve(i + 2, s, dp));
        if (i + 2 < s.size())
            res = max(res, s[i] + s[i + 1] + s[i + 2] - solve(i + 3, s, dp));
        return dp[i] = res;
    }
    string stoneGameIII(vector<int> &stoneValue)
    {
        int i = 0;
        vector<int> dp(stoneValue.size(), -1);
        int result = solve(i, stoneValue, dp);

        if (result > 0)
        {
            return "Alice";
        }
        else if (result < 0)
        {
            return "Bob";
        }

        return "Tie";
    }
};