#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // max heap
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> ans;

        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;

            if (i < k)
            {
                pq.push({dist, {points[i][0], points[i][1]}});
            }
            else
            {
                if (dist < pq.top().first)
                {
                    pq.pop();
                    pq.push({dist, {points[i][0], points[i][1]}});
                }
            }
        }

        int i = 0;
        while (!pq.empty() && i < k)
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
            i++;
        }

        return ans;
    }
};

// formula dist = x*x + y*y

// Time complexity : 0(n)
// space complexity: o(k)