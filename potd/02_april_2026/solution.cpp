#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, int j, int neu, vector<vector<int>> &coins, int m, int n,
              int dp[501][501][3])
    {
        // Last row -> reached destination
        if (i == m - 1 && j == n - 1)
        {
            if (coins[i][i] < 0 && neu > 0)
            {
                return 0;
            }

            return dp[i][j][neu] = coins[i][j];
        }

        if (dp[i][j][neu] != INT_MIN)
        {
            return dp[i][j][neu];
        }

        if (i > m - 1 || j > n - 1)
        {
            return INT_MIN;
        }

        // take it
        int take = coins[i][j] + max(solve(i + 1, j, neu, coins, m, n, dp),
                                     solve(i, j + 1, neu, coins, m, n, dp));

        // skip it
        int skip = INT_MIN;
        if (coins[i][j] < 0 && neu > 0)
        {
            int skipdown = solve(i + 1, j, neu - 1, coins, m, n, dp);
            int skipright = solve(i, j + 1, neu - 1, coins, m, n, dp);

            skip = max(skipdown, skipright);
        }

        return dp[i][j][neu] = max(take, skip);
    }
    int maximumAmount(vector<vector<int>> &coins)
    {
        int dp[501][501][3];

        for (int i = 0; i < 501; i++)
        {
            for (int j = 0; j < 501; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        int m = coins.size();
        int n = coins[0].size();

        return solve(0, 0, 2, coins, m, n, dp);
    }
};