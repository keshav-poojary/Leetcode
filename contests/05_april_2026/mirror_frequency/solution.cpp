#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char getMirror(char c)
    {
        if (c >= 'a' && c <= 'z')
        {
            return 'a' + ('z' - c);
        }
        else if (c >= '0' && c <= '9')
        {
            return '0' + ('9' - c);
        }

        return c;
    }

    int mirrorFrequency(string s)
    {
        map<char, int> mp;
        set<char> st;
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            char mirror = getMirror(c);
            // skip the iteration
            if (st.count(mirror) > 0)
            {
                continue;
            }

            ans = ans + abs(mp[c] - mp[mirror]);
            st.insert(c);
            st.insert(mirror);
        }
        return ans;
    }
};