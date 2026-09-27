#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum = currSum + nums[i];
            maxSum = max(maxSum, currSum);
            if (currSum < 0)
            {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

// Time Complexity: O(n), where n is the length of the input array nums, since we are iterating through the array once.
// Space Complexity: O(1), since we are using only a constant amount of extra space for variables currSum and maxSum.

// Algorithm : Kadanes Algorithm