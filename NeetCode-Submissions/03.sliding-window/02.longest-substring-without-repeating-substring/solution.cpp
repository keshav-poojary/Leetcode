#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;

        int n = s.length();

        int ans = 0;

        map<char, int> mp;

        while (j < n)
        {
            mp[s[j]]++;

            while (mp[s[j]] > 1)
            {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n) in worst case when all characters are distinct.