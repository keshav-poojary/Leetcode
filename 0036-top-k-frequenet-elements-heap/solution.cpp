#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        int i = 0;
        for (auto m : mp)
        {
            if (i < k)
            {
                pq.push({m.second, m.first});
            }
            else
            {
                if (m.second > pq.top().first)
                {
                    pq.pop();
                    pq.push({m.second, m.first});
                }
            }
            i++;
        }

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};