#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 2)
        {
            return n;
        }

        int mask = 0;
        for (int num : nums)
        {
            mask = mask | num;
        }

        return mask + 1;
    }
};

// Time complexity : o(n) -> for traversing the array
// Space complixity : o(1)