#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        stack<int> s;
        map<int, int> ng;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums2[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ng[nums2[i]] = -1;
            }
            else
            {
                ng[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            if (ng.find(nums1[i]) != ng.end())
            {
                ans.push_back(ng[nums1[i]]);
            }
        }

        return ans;
    }
};