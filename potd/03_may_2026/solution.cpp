#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
        {
            return false;
        }

        if ((s + s).find(goal) != -1)
        {
            return true;
        }

        return false;
    }
};

// Time Complexity: O(n) - concatenating and finding the goal string
// Space Complexity: O(n) - concatenating the string s with itself