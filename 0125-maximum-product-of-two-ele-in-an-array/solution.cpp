#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = (nums[n - 1] - 1);
        int b = (nums[n - 2] - 1);
        return a * b;
    }
};

// time complezity -> o(nlogn)
// space complexoity -> o(1)