#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        if (nums.size() == 0)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int count = 0;
        int maxi = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == 1)
            {
                count++;
                maxi = max(maxi, count);
            }
            else if (nums[i] - nums[i - 1] == 0)
            {
                continue;
            }
            else
            {
                count = 0;
            }
        }

        return maxi + 1;
    }
};

// Time Complexity: O(n log n) due to the sorting step, where n is the number of elements in the input array
// Space Complexity: O(1) if we ignore the space used by the sorting algorithm,