#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int one, int two, char ch)
    {
        if (ch == '^')
        {
            return pow(two, one);
        }
        if (ch == '/')
            return two / one;
        if (ch == '*')
            return two * one;
        if (ch == '+')
            return one + two;
        else
            return two - one;
    }

    int evaluatePostfix(vector<string> &arr)
    {
        // code here
        stack<int> s;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i][0] >= '0' && arr[i][0] <= '9')
            {
                s.push(stoi(arr[i]));
            }
            else
            {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                int res = solve(first, second, arr[i][0]);
                s.push(res);
            }
        }

        return s.top();
    }
};

// Time Complexity: O(n) where n is the number of elements in the postfix expression
// Space Complexity: O(n) for the stack in the worst case when all elements are operands