#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        int sum = 0;
        stack<int> s;

        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "+")
            {
                int data1 = s.top();
                s.pop();
                int data2 = s.top();

                s.push(data1);

                s.push(data1 + data2);
            }
            else if (operations[i] == "D")
            {
                s.push(s.top() * 2);
            }
            else if (operations[i] == "C")
            {
                s.pop();
            }
            else
            {
                s.push(stoi(operations[i]));
            }
        }

        while (!s.empty())
        {
            sum = sum + s.top();
            s.pop();
        }

        return sum;
    }
};

// TC : O(N)
// SC : O(N)