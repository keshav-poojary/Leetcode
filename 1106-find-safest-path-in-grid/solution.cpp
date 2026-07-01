#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isFeasible(vector<vector<int>> &dist, int val)
    {
        int n = dist.size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (dist[0][0] < val)
        {
            return false;
        }

        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty())
        {
            auto data = q.front();
            int row = data.first;
            int col = data.second;

            if (row == dist.size() - 1 && col == dist[0].size() - 1)
            {
                return true;
            }

            q.pop();

            int deltar[] = {-1, 0, 1, 0};
            int deltac[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newrow = row + deltar[i];
                int newcol = col + deltac[i];

                if (newrow >= 0 && newcol >= 0 && newrow < dist.size() &&
                    newcol < dist[0].size() && dist[newrow][newcol] >= val &&
                    !vis[newrow][newcol])
                {
                    vis[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // build safest matrix
        while (!q.empty())
        {
            auto data = q.front();
            int row = data.first;
            int col = data.second;
            q.pop();

            int deltar[] = {-1, 0, 1, 0};
            int deltac[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newrow = row + deltar[i];
                int newcol = col + deltac[i];

                if (newrow >= 0 && newcol >= 0 && newrow < grid.size() &&
                    newcol < grid[0].size() &&
                    dist[newrow][newcol] == INT_MAX)
                {
                    dist[newrow][newcol] = dist[row][col] + 1;
                    q.push({newrow, newcol});
                }
            }
        }

        // let use bin search to obtain max safeness factor
        int low = 0;
        int high = 2 * n;
        int ans = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isFeasible(dist, mid))
            {
                low = mid + 1;
                ans = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};

// approach
// 1. we will first build a safest matrix using bfs from all the thief cells
// 2. then we will use binary search to find the max safeness factor
