#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string encode(vector<string> &arr)
    {
        string res = "";

        for (auto s : arr)
        {
            res = res + s;
            res = res + '@';
        }

        return res;
    }

    vector<string> decode(string &s)
    {
        vector<string> res;

        int i = 0;
        int j = s.size() - 1;
        string temp = "";

        while (i <= j)
        {
            if (s[i] == '@')
            {
                res.push_back(temp);
                temp = "";
            }
            else
            {
                temp = temp + s[i];
            }
            i++;
        }
        return res;
    }
};

// Time Complexity: O(n) where n is the total number of characters in the input array of strings
// Space Complexity: O(n) where n is the total number of characters in the input array