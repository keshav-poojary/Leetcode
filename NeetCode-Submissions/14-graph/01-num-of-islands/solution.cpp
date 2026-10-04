#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid,
             int m, int n)
    {
        vis[r][c] = 1;

        int deltaRow[4] = {-1, 0, 1, 0};
        int deltaCol[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newRow = r + deltaRow[i];
            int newCol = c + deltaCol[i];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                !vis[newRow][newCol] && grid[newRow][newCol] == '1')
            {
                dfs(newRow, newCol, vis, grid, m, n);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 0 && grid[i][j] == '1')
                {
                    count++;
                    dfs(i, j, visited, grid, m, n);
                }
            }
        }

        return count;
    }
};

// Time Complexity : O(m *n), where m is the number of rows and n is the number of columns in the input grid, since we are iterating through the entire grid once and performing a depth - first search for each unvisited land cell.
// Space Complexity : O(m *n), where m is the number of rows and n is the