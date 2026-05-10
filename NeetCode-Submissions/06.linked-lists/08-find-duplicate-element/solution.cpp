#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        set<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
            {
                return nums[i];
            }
            else
            {
                s.insert(nums[i]);
            }
        }

        return 0;
    }
};

// Time Complexity: O(n) where n is the number of elements in the input array.
// Space Complexity: O(n) since we are using a set to store the elements of the input array.