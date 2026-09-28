#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxChildren(vector<int> &greed, vector<int> &cookie)
    {
        // code here
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());

        int left = 0;
        int right = 0;
        int count = 0;

        while (left < cookie.size() && right < greed.size())
        {
            if (cookie[left] >= greed[right])
            {
                count++;
                left++;
                right++;
            }
            else if (cookie[left] < greed[right])
            {
                left++;
            }
        }
        return count;
    }
};

// Time Complexity: O(nlogn + mlogm), where n is the length of the input array greed and m is the length of the input array cookie, since we are sorting both arrays.
// Space Complexity: O(1), since we are using only a constant amount of extra space