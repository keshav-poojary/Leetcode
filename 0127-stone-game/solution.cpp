#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[501][501];

    int solve(int i, int j, vector<int> &piles)
    {
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (i == j)
        {
            return piles[i];
        }

        int take_i =
            piles[i] + min(solve(i + 1, j, piles), solve(i + 1, j - 1, piles));
        int take_j =
            piles[j] + min(solve(i + 1, j - 1, piles), solve(i, j - 2, piles));
        return dp[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int> &piles)
    {
        int total = 0;

        for (int i = 0; i < 501; i++)
        {
            for (int j = 0; j < 501; j++)
            {
                dp[i][j] = -1;
            }
        }

        total = accumulate(piles.begin(), piles.end(), 0);

        int alice_score = solve(0, piles.size() - 1, piles);

        int bob_score = total - alice_score;

        return alice_score > bob_score;
    }
};

// time complexity: O(n^2) where n is the number of piles
// space complexity: O(n^2) where n is the number of piles