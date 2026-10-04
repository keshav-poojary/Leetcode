#include <bits/stdc++.h>
using namespace std;

// Djkstra's Algorithm

class Solution
{
public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src)
    {
        // code here
        vector<vector<pair<int, int>>> adjList(V);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            adjList[u].push_back({v, t});
        }

        vector<int> times(V, INT_MAX);
        queue<int> q;
        q.push(src);
        times[src] = 0;

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (auto ngbr : adjList[u])
            {
                int v = ngbr.first;
                int t = ngbr.second;

                if (times[v] > times[u] + t)
                {
                    times[v] = times[u] + t;
                    q.push(v);
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < times.size(); i++)
        {
            if (times[i] == INT_MAX)
            {
                return -1;
            }
            maxi = max(maxi, times[i]);
        }

        return maxi;
    }
};

// time complexity: O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph, since we are performing a breadth-first search to calculate the minimum time for all nodes to receive the signal.
// space complexity: O(V + E), where V is the number of vertices (nodes)