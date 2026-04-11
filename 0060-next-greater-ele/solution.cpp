#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        // code here
        vector<int> ans;
        stack<int> s;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            long long current = arr[i];

            while (s.size() != 0 && current >= s.top())
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
            s.push(current);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)