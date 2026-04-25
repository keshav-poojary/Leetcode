#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> leftMax;
        vector<int> rightMax;

        int maxi = INT_MIN;

        for (int i = 0; i < height.size(); i++)
        {
            maxi = max(maxi, height[i]);
            leftMax.push_back(maxi);
        }

        maxi = INT_MIN;
        for (int i = height.size() - 1; i >= 0; i--)
        {
            maxi = max(maxi, height[i]);
            rightMax.push_back(maxi);
        }

        reverse(rightMax.begin(), rightMax.end());

        int trap = 0;
        for (int i = 0; i < height.size(); i++)
        {
            trap = trap + min(leftMax[i], rightMax[i]) - height[i];
        }

        return trap;
    }
};

// Time Complexity: O(n) where n is the number of elements in the input array, since we need to iterate through the array a few times to calculate the left and right maximums and then calculate the trapped water
// Space Complexity: O(n) where n is the number of elements in the input array, since we are using two additional arrays to store the left and right maximums