#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMiddleElementUnique(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        int mid = nums[nums.size() / 2];
        if (mp[mid] > 1)
        {
            return false;
        }

        return true;
    }
};

// Time Complexity: O(n) where n is the number of elements in the input array nums. This is because we are iterating through the array once to count the occurrences of each element using a map.
// Space Complexity: O(n) for storing the counts of each element in the map. In