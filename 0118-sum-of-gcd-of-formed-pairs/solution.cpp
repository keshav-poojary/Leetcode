#include <bits/stdc++.h>
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
    long long gcdSum(vector<int> &nums)
    {

        vector<long long> prefixGcd(nums.size(), 0);
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        int low = 0;
        int high = prefixGcd.size() - 1;

        while (low < high)
        {
            sum = sum + gcd(prefixGcd[low], prefixGcd[high]);
            low++;
            high--;
        }

        return sum;
    }
};

// time complexity : o(nlogn);
// space comp : o(n)