#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        set<int> s;
        vector<int> res;

        s.insert(nums.begin(), nums.end());

        for (int i = mini; i <= maxi; i++)
        {
            if (s.find(i) == s.end())
            {
                res.push_back(i);
            }
        }

        return res;
    }
};

// time complexity: O(n)
// space complexity: O(n)