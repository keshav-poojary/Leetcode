#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> freq(26, 0);
        vector<int> vis(26, 0);
        string st;

        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        for (auto ch : s)
        {
            freq[ch - 'a']--;

            if (vis[ch - 'a'])
            {
                continue;
            }

            while (!st.empty() && ch < st.back() && freq[st.back() - 'a'] > 0)
            {
                vis[st.back() - 'a'] = 0;
                st.pop_back();
            }

            st.push_back(ch);
            vis[ch - 'a'] = 1;
        }

        return st;
    }
};

