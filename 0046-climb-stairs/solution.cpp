#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 1;
        }

        if (n < 0)
        {
            return 0;
        }

        if (dp[n] != INT_MIN)
        {
            return dp[n];
        }

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, INT_MIN);
        return solve(n, dp);
    }
};