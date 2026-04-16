#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            sort(grid[i].begin(), grid[i].end());
        }

        for (int col = 0; col < n; col++)
        {
            int maxi = 0;
            for (int row = 0; row < m; row++)
            {
                maxi = max(maxi, grid[row][col]);
            }

            ans = ans + maxi;
        }

        return ans;
    }
};

// Time Complexity: O(m*n*log(n)) + O(m*n) ~ O(m*n*log(n))
// Space Complexity: O(1)