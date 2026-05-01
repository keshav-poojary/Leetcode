#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int val = 0;
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "X++" || operations[i] == "++X")
            {
                val = val + 1;
            }
            else
            {
                val = val - 1;
            }
        }
        return val;
    }
};
// Time Complexity: O(n) where n is the number of elements in the input array, since we need to iterate through the array once to calculate the final value after performing all operations
// Space Complexity: O(1) since we are using only a constant amount of extra space