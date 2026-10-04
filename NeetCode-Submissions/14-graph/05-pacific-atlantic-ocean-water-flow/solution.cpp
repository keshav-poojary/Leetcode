#include <32bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &heights,
             vector<vector<int>> &ocean)
    {
        int rDelta[4] = {-1, 0, 1, 0};
        int cDelta[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newrow = r + rDelta[i];
            int newcol = c + cDelta[i];

            // check if the new cell is out of bounds or already visited by the ocean
            // if the new cell is out of bounds or already visited by the ocean, continue to the next iteration
            if (newrow < 0 || newrow > heights.size() - 1 ||
                newcol > heights[0].size() - 1 || newcol < 0 ||
                ocean[newrow][newcol] == 1)
            {
                continue;
            }

            // check if the new cell is greather than the current cell, if it is, mark the new cell as visited by the ocean and perform dfs on the new cell
            if (newrow >= 0 && newrow < heights.size() && newcol >= 0 &&
                newcol < heights[0].size() &&
                heights[newrow][newcol] >= heights[r][c])
            {
                ocean[newrow][newcol] = 1;
                dfs(newrow, newcol, heights, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();
        // for result
        vector<vector<int>> res;

        // for pacific and atlantic ocean
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // for all the cells in first row and first column, mark them as reachable by pacific ocean

                if (i == 0 || j == 0)
                {
                    pacific[i][j] = 1;
                }

                // for all the cells in last row and last column, mark them as reachable by atlantic ocean
                if (i == rows - 1 || j == cols - 1)
                {
                    atlantic[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // if the cell is reachable by pacific ocean, perform dfs to mark all the cells that can reach pacific ocean
                if (pacific[i][j] == 1)
                {
                    dfs(i, j, heights, pacific);
                }
                // if the cell is reachable by atlantic ocean, perform dfs to mark all the cells that can reach atlantic ocean
                if (atlantic[i][j] == 1)
                {
                    dfs(i, j, heights, atlantic);
                }
            }
        }

        // for all the cells that can reach both pacific and atlantic ocean, add them to the result vector
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1)
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};

// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the input matrix heights, since we are iterating through the entire matrix once and performing a depth - first search for each cell that can reach both oceans.
// Space Complexity: O(m * n), where m is the number of rows and n is