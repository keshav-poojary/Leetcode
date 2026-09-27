#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        bool reached = true;
        int maxIndex = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > maxIndex)
            {
                reached = false;
                break;
            }

            maxIndex = max(maxIndex, i + nums[i]);
        }
        return reached;
    }
};

// Time Complexity: O(n), where n is the length of the input array nums, since we are iterating through the array once.
// Space Complexity: O(1), since we are using only a constant amount of extra space