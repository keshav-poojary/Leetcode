#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }

        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> v;

        for (auto m : mp)
        {
            pair<int, int> p = make_pair(m.first, m.second);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), comp);

        vector<int> res;
        for (auto data : v)
        {
            res.push_back(data.first);
            k--;
            if (k == 0)
            {
                break;
            }
        }

        return res;
    }
};

// Time Complexity: O(n log n) where n is the number of unique elements in the input array
// Space Complexity: O(n) where n is the number of unique elements in the input array