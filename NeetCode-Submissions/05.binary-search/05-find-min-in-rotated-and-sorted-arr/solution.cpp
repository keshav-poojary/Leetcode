#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        int mini = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[low] <= nums[mid])
            {
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            else
            {
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }

        return mini;
    }
};

// Time Complexity: O(log n) where n is the number of elements in the array
// Space Complexity: O(1)