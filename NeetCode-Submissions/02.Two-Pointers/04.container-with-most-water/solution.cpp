#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxi = INT_MIN;

        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            maxi = max(maxi, area);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxi;
    }
};

// Time Complexity: O(n) where n is the number of elements in the input array, since we may need to iterate through the array once in the worst case
// Space Complexity: O(1) since we are using only a constant amount of extra space