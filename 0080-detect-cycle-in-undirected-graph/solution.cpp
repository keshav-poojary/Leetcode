#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Code here
        vector<int> adj[V];
        vector<int> visited(V, 0);

        // step 1: create adj list
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // for each component, check if cycle exist or not
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool ans = isCycleExist(adj, visited, i);
                if (ans)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycleExist(vector<int> adj[], vector<int> &visited, int node)
    {
        map<int, int> parent;
        queue<int> q;

        q.push(node);
        parent[node] = -1;
        visited[node] = 1;

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (auto ngbr : adj[top])
            {
                // if ngbr is not visited, then visit it and mark parent
                if (!visited[ngbr])
                {
                    visited[ngbr] = 1;
                    q.push(ngbr);
                    parent[ngbr] = top;
                }
                // if ngbr is visited and parent of top is not ngbr, then cycle exist
                else if (visited[ngbr] && parent[top] != ngbr)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)