#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<int> &nums)
    {

        // base case if i is greater than j then return 0 (no elements left to choose)
        if (i > j)
        {
            return 0;
        }

        // base case if i is equal to j then return nums[i] (only one element left to choose)
        if (i == j)
        {
            return nums[i];
        }

        // you choose i and your opponent will let you choose the minimum of the two options (i+2, j) or (i+1, j-1)
        // you choose j and your opponent will let you choose the minimum of the two options (i+1, j-1) or (i, j-2)
        int take_i =
            nums[i] + min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));
        int take_j =
            nums[j] + min(solve(i + 1, j - 1, nums), solve(i, j - 2, nums));

        // return the maximum of the two options
        return max(take_i, take_j);
    }
    bool predictTheWinner(vector<int> &nums)
    {
        int total = 0;

        total = accumulate(nums.begin(), nums.end(), 0);

        int player1_score = solve(0, nums.size() - 1, nums);

        int player2_score = total - player1_score;

        return player1_score >= player2_score;
    }
};