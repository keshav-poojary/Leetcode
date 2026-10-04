#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRot(vector<vector<int>> &mat)
    {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        int vis[m][n];

        int time = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        while (!q.empty())
        {
            auto top = q.front();
            int r = top.first.first;
            int c = top.first.second;
            int t = top.second;
            time = max(time, t);
            q.pop();

            int rDelta[4] = {-1, 0, 1, 0};
            int cDelta[4] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newrow = r + rDelta[i];
                int newcol = c + cDelta[i];

                if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && vis[newrow][newcol] != 2 && mat[newrow][newcol] == 1)
                {
                    q.push({{newrow, newcol}, t + 1});
                    vis[newrow][newcol] = 2;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1 && vis[i][j] != 2)
                {
                    return -1;
                }
            }
        }

        return time;
    }
};

// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the input matrix mat, since we are iterating through the entire matrix once and performing a breadth-first search for each rotten orange.
// Space Complexity: O(m * n), where m is the number of rows and n is