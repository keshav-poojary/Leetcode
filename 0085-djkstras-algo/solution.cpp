#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<pair<int, int>> adj[V];

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> distance(V, INT_MAX);
        queue<int> q;
        q.push(src);
        distance[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto ngbr : adj[node])
            {
                int ngbrNode = ngbr.first;
                int weight = ngbr.second;

                if (distance[ngbrNode] > distance[node] + weight)
                {
                    distance[ngbrNode] = distance[node] + weight;
                    q.push(ngbrNode);
                }
            }
        }

        return distance;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)