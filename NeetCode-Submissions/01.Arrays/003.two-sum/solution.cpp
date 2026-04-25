#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int compliment = target - nums[i];
            if (mp.find(compliment) != mp.end())
            {
                return {mp[compliment], i};
            }
            mp[nums[i]] = i;
        }

        return {};
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)