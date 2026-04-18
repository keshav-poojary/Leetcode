
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int value, int x, int y, int z, vector<int> &dp)
    {
        if (value == 0)
        {
            return 0;
        }

        if (value < 0)
        {
            return INT_MIN;
        }

        if (dp[value] != -1)
        {
            return dp[value];
        }

        int xvalue = 1 + solve(value - x, x, y, z, dp);
        int yvalue = 1 + solve(value - y, x, y, z, dp);
        int zvalue = 1 + solve(value - z, x, y, z, dp);

        return dp[value] = max(xvalue, max(yvalue, zvalue));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        vector<int> dp(n + 1, -1);
        int ans = solve(n, x, y, z, dp);
        if (ans < 0)
        {
            return 0;
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)