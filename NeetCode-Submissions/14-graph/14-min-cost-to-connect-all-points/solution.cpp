#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int manh_dist(vector<int> a, vector<int> b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        // {manhattan_distance, v}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int cost = 0;
        int n = points.size();
        vector<int> vis(n, 0);
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [weight, u] = pq.top();
            pq.pop();

            if (vis[u])
            {
                continue;
            }

            cost = cost + weight;
            vis[u] = 1;

            for (int v = 0; v < n; v++)
            {
                if (!vis[v])
                {
                    int dist = manh_dist(points[u], points[v]);
                    pq.push({dist, v});
                }
            }
        }

        return cost;
    }
};

// Time Complexity: O(n^2 * logn), where n is the number of points, since we are using a priority queue to store the edges and performing a breadth-first search to traverse the graph.
// Space Complexity: O(n^2), where n is the number of points, since we

// Algorithm: Prim's Algorithm, For each point, we calculate the Manhattan distance to all other points and add them to a priority queue. We then pop the minimum distance from the queue and add it to the total cost, marking the point as visited. We repeat this process until all points are visited.