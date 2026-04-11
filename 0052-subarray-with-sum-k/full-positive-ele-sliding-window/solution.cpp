#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        // code her

        int left = 0;
        long long curSum = 0;

        for (int i = 0; i < arr.size(); i++)
        {

            curSum = curSum + arr[i];

            while (curSum > target)
            {
                curSum = curSum - arr[left];
                left++;
            }

            if (curSum == target)
            {
                return {left + 1, i + 1};
            }
        }

        return {-1};
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)