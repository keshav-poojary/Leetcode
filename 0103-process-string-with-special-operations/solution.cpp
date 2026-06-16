#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string obtainReverse(string &s)
    {
        reverse(s.begin(), s.end());
        return s;
    }
    string processStr(string s)
    {
        string result;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (isalpha(ch))
            {
                result += ch;
            }
            else if (ch == '#')
            {
                result += result;
            }
            else if (ch == '%')
            {
                string res = obtainReverse(result);
                result = res;
            }
            else if (ch == '*')
            {
                if (!result.empty())
                {
                    result.pop_back();
                }
            }
        }
        return result;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)