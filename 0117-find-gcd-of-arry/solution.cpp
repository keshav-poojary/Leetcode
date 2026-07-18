#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
    int findGCD(vector<int> &nums)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        return gcd(mini, maxi);
    }
};

// Time Complexity: O(n) where n is the size of the input array. We iterate through the array to find the minimum and maximum values, and then we compute the GCD of those two values.
//  Space Complexity: O(1) since we are using a constant amount of space to store the minimum and maximum values and the GCD result.