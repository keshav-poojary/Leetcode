#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<string> s;

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] != '.')
                {
                    string val = string(1, board[r][c]);

                    string row = val + "row" + to_string(r);
                    string col = val + "column" + to_string(c);
                    string box =
                        val + "box" + to_string(r / 3) + to_string(c / 3);

                    if (s.find(row) != s.end() || s.find(col) != s.end() ||
                        s.find(box) != s.end())
                    {
                        return false;
                    }

                    s.insert(row);
                    s.insert(col);
                    s.insert(box);
                }
            }
        }

        return true;
    }
};

// Time Complexity: O(1) since the board size is fixed at 9x9
// Space Complexity: O(1) since the maximum number of entries in the set is limited by the fixed size of the board (9 rows, 9 columns, and 9 boxes)