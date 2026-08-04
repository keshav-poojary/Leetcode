#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int idx, vector<string> &res, string output,
               map<char, string> &mp, string digits, int n)
    {
        // base case
        if (idx >= n)
        {
            res.push_back(output);
            return;
        }

        string data = mp[digits[idx]];
        for (int i = 0; i < data.size(); i++)
        {
            output.push_back(data[i]);
            solve(idx + 1, res, output, mp, digits, n);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        int index = 0;
        int n = digits.size();
        vector<string> res;
        string output = "";
        map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(index, res, output, mp, digits, n);

        return res;
    }
};