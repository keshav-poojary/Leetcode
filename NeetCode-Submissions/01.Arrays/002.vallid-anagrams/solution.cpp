#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int size1 = s.size();
        int size2 = t.size();

        if (size1 != size2)
        {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t)
        {
            return true;
        }

        return false;
    }
};

// Time Complexity: O(n log n)
// Space Complexity: O(1)