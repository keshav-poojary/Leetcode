#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[501][501];

    int solve(int i, int j, string word1, string word2)
    {
        if (i == word1.size())
        {
            return word2.length() - j;
        }

        if (j == word2.size())
        {
            return word1.length() - i;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = INT_MAX;
        if (word1[i] == word2[j])
        {
            return solve(i + 1, j + 1, word1, word2);
        }
        else
        {
            // insert
            int insertAns = 1 + solve(i, j + 1, word1, word2);

            // delete
            int deleteAns = 1 + solve(i + 1, j, word1, word2);

            // replace
            int replaceAns = 1 + solve(i + 1, j + 1, word1, word2);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, word1, word2);
    }
};