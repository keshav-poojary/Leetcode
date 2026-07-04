#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> vis(n + 1, false);
        queue<int> q;

        q.push(1);
        vis[1] = true;

        int mini = INT_MAX;

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (auto data : adj[top])
            {
                int edge = data.first;
                int cost = data.second;
                mini = min(mini, cost);

                if (!vis[edge])
                {
                    q.push(edge);
                    vis[edge] = true;
                }
            }
        }

        return mini;
    }
};

// Time Complexity: O(V + E) where V is the number of vertices (cities) and E is the number of edges (roads). This is because we are performing a breadth-first search (BFS) traversal of the graph, which visits each vertex and edge once.
// Space Complexity: O(V + E) for storing the adjacency list and the visited array.

// Approach
// 1. Create an adjacency list to represent the graph of cities and roads.
// 2. Initialize a visited array to keep track of visited cities and a queue for BFS
// 3. Start BFS from city 1, marking it as visited and pushing it into the queue.
// 4. While the queue is not empty, pop a city from the front of the queue and check its neighbors.
// 5. For each neighbor, update the minimum score (minimum distance of a road)
