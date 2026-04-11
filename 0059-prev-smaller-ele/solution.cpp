#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> prevSmaller(vector<int> &arr)
    {
        //  code here
        vector<int> ans;
        stack<int> s;

        for (int i = 0; i < arr.size(); i++)
        {
            while (s.size() != 0 && arr[i] <= s.top())
            {
                s.pop();
            }

            if (s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(arr[i]);
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)