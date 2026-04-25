#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> s;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }

        for (auto v : s)
        {
            res.push_back(v);
        }

        return res;
    }
};

// Time Complexity: O(n^2) where n is the number of elements in the input array, since we have a nested loop to find the triplets
// Space Complexity: O(n) in the worst case, if all triplets are unique and