#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countValidPrefixes(string s)
    {
        int zeroesCount = 0;
        int onesCount = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '0')
            {
                zeroesCount++;
            }
            else
            {
                onesCount++;
            }

            if (abs(zeroesCount - onesCount) <= 1)
            {
                ans++;
            }
        }

        return ans;
    }
};

// time complexity: O(n) where n is the length of the string s
// space complexity: O(1)
