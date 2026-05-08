#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();

        int start = 0;
        int end = (rows * columns) - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            int ele = matrix[mid / columns][mid % columns];

            if (ele == target)
            {
                return true;
            }
            else if (ele > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return false;
    }
};

// Time Complexity: O(log(m*n)) where m is the number of rows and n is the number of columns in the matrix
// Space Complexity: O(1)