#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool feasible(int mid, vector<int> piles, int h)
    {
        long long hour = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            // formula = (value + mid-1/mid)
            hour = hour + (piles[i] + mid - 1) / mid;
        }

        return hour <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int start = 1;
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            maxi = max(maxi, piles[i]);
        }
        int end = maxi;

        int ans = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (feasible(mid, piles, h))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};
// Time Complexity: O(n log m) where n is the number of piles and m is the maximum number of bananas in a pile
// Space Complexity: O(1)