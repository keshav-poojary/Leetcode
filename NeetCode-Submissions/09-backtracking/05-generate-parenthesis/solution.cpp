#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string &output, int openBr, int closeBr, vector<string> &ans,
               int n)
    {
        if (openBr == 0 && closeBr == 0)
        {
            ans.push_back(output);
            return;
        }

        if (openBr == closeBr)
        {
            string op1 = output;
            op1.push_back('(');
            solve(op1, openBr - 1, closeBr, ans, n);
        }
        else if (openBr == 0)
        {
            string op1 = output;
            op1.push_back(')');
            solve(op1, openBr, closeBr - 1, ans, n);
        }
        else if (closeBr == 0)
        {
            string op1 = output;
            op1.push_back('(');
            solve(op1, openBr - 1, closeBr, ans, n);
        }
        else
        {
            string op1 = output;
            string op2 = output;
            op1.push_back('(');
            op2.push_back(')');
            solve(op1, openBr - 1, closeBr, ans, n);
            solve(op2, openBr, closeBr - 1, ans, n);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        int openBr = n;
        int closeBr = n;
        vector<string> ans;
        string output = "";
        solve(output, openBr, closeBr, ans, n);
        return ans;
    }
};