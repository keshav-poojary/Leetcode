#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }

        return -1;
    }
};

// Time Complexity: O(logn) - binary search
// Space Complexity: O(1) - constant space