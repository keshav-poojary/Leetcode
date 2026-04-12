#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                {
                    count++;
                }
                else
                {

                    if (ch == ')' && st.top() == '(')
                    {
                        st.pop();
                    }

                    if (ch == ']' && st.top() == '[')
                    {
                        st.pop();
                    }

                    if (ch == '}' && st.top() == '{')
                    {
                        st.pop();
                    }
                }
            }
        }

        count = count + st.size();
        return count;
    }
};

// time complexity: O(n) where n is the length of the input string
// space complexity: O(n) in the worst case when all characters in the string are opening parentheses