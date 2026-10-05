#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestCost(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // code here
        vector<vector<pair<int, int>>> adjList(n);

        for (auto flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];
            adjList[u].push_back({v, cost});
        }

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        // {stop, {node, cost}}
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int step = top.first;
            int node = top.second.first;
            int cost = top.second.second;

            if (step > k)
            {
                continue;
            }

            for (auto ngbr : adjList[node])
            {
                int ngbrNode = ngbr.first;
                int ngbrCost = ngbr.second;
                if (cost + ngbrCost < dist[ngbrNode] && step <= k)
                {
                    dist[ngbrNode] = cost + ngbrCost;
                    pq.push({step + 1, {ngbrNode, cost + ngbrCost}});
                }
            }
        }

        if (dist[dst] == 1e9)
        {
            return -1;
        }

        return dist[dst];
    }
};

// Time complexity: O(ElogV) where E is the number of edges and V is the number of vertices. The priority queue will have at most E elements, and each operation on the priority queue takes O(logV) time.
// Space complexity: O(V + E) for the adjacency list and O(V) for the distance array.