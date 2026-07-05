#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<bool> rowsTrack(r, false);
        vector<bool> colsTrack(c, false);

        // track rows and cols one
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowsTrack[i] = true;
                    colsTrack[j] = true;
                }
            }
        }

        // set matrix values zero
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (rowsTrack[i] || colsTrack[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the input matrix. This is because we are iterating through all the elements of the matrix twice, once to track the rows and columns that need to be set to zero, and once to set the values to zero.
// Space Complexity: O(m+n) for storing the rows and columns that need to be set