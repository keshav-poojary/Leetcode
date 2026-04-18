#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int sum = 0;
        for (int i = 1; i < s.size(); i++)
        {
            int val = abs(int(s[i - 1]) - int(s[i]));
            sum = sum + val;
        }
        return sum;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)