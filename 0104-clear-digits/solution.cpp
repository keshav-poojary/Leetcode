#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string clearDigits(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (isalpha(ch))
            {
                st.push(ch);
            }
            else
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