#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find(vector<vector<char>> &board, string word, int index, int i, int j,
              int m, int n, vector<vector<int>> &vis)
    {
        // base case
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] ||
            board[i][j] != word[index])
        {
            return false;
        }

        if (index == word.size() - 1 && board[i][j] == word[index])
        {
            return true;
        }

        vis[i][j] = 1;

        bool found = (find(board, word, index + 1, i - 1, j, m, n, vis) ||
                      find(board, word, index + 1, i, j + 1, m, n, vis) ||
                      find(board, word, index + 1, i + 1, j, m, n, vis) ||
                      find(board, word, index + 1, i, j - 1, m, n, vis));

        vis[i][j] = 0;

        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int index = 0;
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[index])
                {
                    if (find(board, word, index, i, j, m, n, visited))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};