#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        // storing indexes
        stack<int> s;
        vector<int> ans;

        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(s.top() - i);
            }

            s.push(i);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)