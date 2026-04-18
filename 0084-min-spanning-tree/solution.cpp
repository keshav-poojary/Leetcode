#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<pair<int, int>> adj[V];

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> vis(V, 0);

        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int node = top.second;
            int weight = top.first;

            if (vis[node])
                continue;

            vis[node] = 1;
            sum += weight;

            for (auto it : adj[node])
            {
                int ngbr = it.first;
                int edgeWeight = it.second;

                if (!vis[ngbr])
                {
                    pq.push({edgeWeight, ngbr});
                }
            }
        }

        return sum;
    }
};

// Time Complexity: O(E*log(V))
// Space Complexity: O(V + E)