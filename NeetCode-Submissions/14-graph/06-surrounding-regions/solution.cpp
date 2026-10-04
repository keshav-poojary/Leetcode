#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int r, int c, vector<vector<char>> &board,
             vector<vector<int>> &vis, int m, int n)
    {
        int rDelta[4] = {-1, 0, 1, 0};
        int cDelta[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newrow = r + rDelta[i];
            int newcol = c + cDelta[i];

            if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n &&
                vis[newrow][newcol] == 0 && board[newrow][newcol] == 'O')
            {
                vis[newrow][newcol] = 1;
                dfs(newrow, newcol, board, vis, m, n);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        for (int i = 0; i < cols; i++)
        {
            // first row
            if (board[0][i] == 'O' && vis[0][i] == 0)
            {
                vis[0][i] = 1;
                dfs(0, i, board, vis, rows, cols);
            }
            // last row
            if (board[rows - 1][i] == 'O' && vis[rows - 1][i] == 0)
            {
                vis[rows - 1][i] = 1;
                dfs(rows - 1, i, board, vis, rows, cols);
            }
        }

        for (int i = 0; i < rows; i++)
        {
            // first col
            if (board[i][0] == 'O' && vis[i][0] == 0)
            {
                vis[i][0] = 1;
                dfs(i, 0, board, vis, rows, cols);
            }
            // last col
            if (board[i][cols - 1] == 'O' && vis[i][cols - 1] == 0)
            {
                vis[i][cols - 1] = 1;
                dfs(i, cols - 1, board, vis, rows, cols);
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'O' && vis[i][j] != 1)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// time complexity : O(n*m), where n is the number of rows and m is the number of columns in the input board, since we are iterating through the entire board once and performing a depth - first search for each unvisited 'O' cell.
// space complexity : O(n*m), where n is the number of rows and m is the