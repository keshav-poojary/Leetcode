#include <string>
using namespace std;
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int starti = 0;
        int startj = 0;

        for (int i = 0; i < moves.length(); i++)
        {
            if (moves[i] == 'U')
            {
                starti--;
            }
            else if (moves[i] == 'D')
            {
                starti++;
            }
            else if (moves[i] == 'R')
            {
                startj++;
            }
            else
            {
                startj--;
            }
        }

        return starti == 0 && startj == 0;
    }
};