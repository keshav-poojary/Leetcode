#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int node, vector<int> &vis, queue<int> q, vector<int> adjList[])
    {
        vis[node] = 1;
        q.push(node);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (auto ngbr : adjList[curr])
            {
                if (!vis[ngbr])
                {
                    vis[ngbr] = 1;
                    q.push(ngbr);
                }
            }
        }
    }
    int countConnected(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<int> adjList[V];

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        vector<int> vis(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                count++;
                bfs(i, vis, q, adjList);
            }
        }

        return count;
    }
};

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph, since we are performing a breadth-first search to traverse all connected components.
// Space Complexity: O(V + E), where V is the number of vertices and E is