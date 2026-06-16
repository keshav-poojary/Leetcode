#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (isalpha(ch))
            {
                st.push(ch);
            }
            else if (ch == '*')
            {
                st.pop();
            }
        }

        string res;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)