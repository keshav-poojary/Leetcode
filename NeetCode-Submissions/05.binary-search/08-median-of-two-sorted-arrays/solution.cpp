#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> arr;

        for (int i = 0; i < nums1.size(); i++)
        {
            arr.push_back(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            arr.push_back(nums2[i]);
        }

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int mid = n / 2;

        if (n % 2 != 0)
        {
            return double(arr[mid]);
        }
        else
        {
            return double(arr[mid] + arr[mid - 1]) / 2;
        }

        return 0;
    }
};

// Time Complexity: O((m+n) log (m+n)) where m and n are the sizes of the two input arrays
// Space Complexity: O(m+n) where m and n are the sizes of the two input