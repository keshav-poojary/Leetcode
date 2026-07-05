#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size();

        int total = row * col;
        int count = 0;

        int startRow = 0;
        int startCol = 0;
        int endRow = row - 1;
        int endCol = col - 1;

        while (count < total)
        {
            // print print row
            for (int index = startCol; count < total && index <= endCol; index++)
            {
                ans.push_back(matrix[startRow][index]);
                count++;
            }
            startRow++;

            // print last column
            for (int index = startRow; count < total && index <= endRow; index++)
            {
                ans.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;

            // print last row
            for (int index = endCol; count < total && index >= startCol; index--)
            {
                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;

            for (int index = endRow; count < total && index >= startRow; index--)
            {
                ans.push_back(matrix[index][startCol]);
                count++;
            }
            startCol++;
        }

        return ans;
    }
};

// Time Complexity: O(n) where n is the number of elements in the input matrix. This is because we are iterating through all the elements of the matrix once to collect them in spiral order.
// Space Complexity: O(n) for storing the elements of the matrix in the ans vector.