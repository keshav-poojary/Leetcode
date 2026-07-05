#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sumOfNaturalNumbers = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            sumOfNaturalNumbers = sumOfNaturalNumbers + i;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }

        return sumOfNaturalNumbers - sum;
    }
};