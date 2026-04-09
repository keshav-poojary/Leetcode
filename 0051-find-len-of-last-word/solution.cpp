#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }

        int ans = 0;
        while (i >= 0 && s[i] != ' ')
        {
            ans++;
            i--;
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)