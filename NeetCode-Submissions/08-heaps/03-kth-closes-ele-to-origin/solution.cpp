#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>> pq;

        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            int distance = x * x + y * y;

            if (i < k)
            {
                pq.push({distance, {x, y}});
            }
            else
            {
                if (distance < pq.top().first)
                {
                    pq.pop();
                    pq.push({distance, {x, y}});
                }
            }
        }

        vector<vector<int>> res;

        while (!pq.empty() && k--)
        {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return res;
    }
};

// Time Complexity: O(nlogK) for iterating through the points and maintaining the priority queue
// Space Complexity: O(K) for the priority queue and O(K) for the result vector