#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    long long maxPairStrength(vector<int> &nums)
    {
        long long maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                long long mul = 1LL * nums[i] * nums[j];
                long long gcdRes = gcd(nums[i], nums[j]);
                long long gcdSquare = gcdRes * gcdRes;
                long long res = mul / gcdSquare;
                maxi = max(maxi, res);
            }
        }

        return maxi;
    }
};

// time complexity: O(n^2) where n is the length of the array nums
// space complexity: O(1)