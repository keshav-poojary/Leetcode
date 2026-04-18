#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
        {
            return 0;
        }

        if (amount < 0)
        {
            return INT_MAX;
        }

        if (dp[amount] != -1)
        {
            return dp[amount];
        }

        int mini = INT_MAX;

        for (auto coin : coins)
        {
            int ans = solve(coins, amount - coin, dp);
            if (ans != INT_MAX)
            {
                mini = min(mini, 1 + ans);
            }
        }

        return dp[amount] = mini;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        int res = solve(coins, amount, dp);
        if (res == INT_MAX)
        {
            return -1;
        }
        return res;
    }
};