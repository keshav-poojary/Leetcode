
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // step 1: transpose the matrix

        int r = matrix.size();
        int c = matrix[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // step 2: reverse rows
        for (int i = 0; i < r; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// time complexity: O(n^2) where n is the number of rows or columns in the matrix
// space complexity: O(1) since we are doing the rotation in place