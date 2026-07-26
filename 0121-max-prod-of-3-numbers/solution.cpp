#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // option1 : product of 3 largest numbers
        int res1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        // option2 : product of 2 smallest numbers and the largest number
        int res2 = nums[0] * nums[1] * nums[n - 1];
        // maximum is the answer
        int ans = max(res1, res2);
        return ans;
    }
};

// Time Complexity: O(nlogn) due to sorting the array
// Space complexity: O(1) as we are using constant space