#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // code here

        // minheap -> {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> adj(V);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> vis(V, 0);
        int sum = 0;

        pq.push({0, 0});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int weight = top.first;
            int node = top.second;

            if (vis[node] == 1)
            {
                continue;
            }

            sum = sum + weight;
            vis[node] = 1;

            for (auto ngbr : adj[node])
            {
                if (!vis[ngbr.first])
                {
                    pq.push({ngbr.second, ngbr.first});
                }
            }
        }

        return sum;
    }
};

// time complexity: O(ElogV), where E is the number of edges and V is the number of vertices in the graph, since we are using a priority queue to store the edges and performing a breadth-first search to traverse the graph.
// space complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph, since we are storing the adjacency list and the visited array.