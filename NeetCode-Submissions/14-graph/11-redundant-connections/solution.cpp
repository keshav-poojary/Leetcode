#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCycleExist(vector<int> adj[], vector<int> &visited, int node)
    {
        map<int, int> childToParentMappping;
        queue<int> q;

        q.push(node);
        childToParentMappping[node] = -1;
        visited[node] = 1;

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (auto ngbr : adj[top])
            {
                if (!visited[ngbr])
                {
                    visited[ngbr] = 1;
                    q.push(ngbr);
                    childToParentMappping[ngbr] = top;
                }
                else if (visited[ngbr] &&
                         childToParentMappping[top] != ngbr)
                {
                    return true;
                }
            }
        }

        return false;
    }
    bool checkCycleIfAdded(int u, int v, vector<int> adjList[], int n)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);

        vector<int> vis(n + 1, 0);
        if (isCycleExist(adjList, vis, u))
        {
            return true;
        }

        adjList[u].pop_back();
        adjList[v].pop_back();

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> adjList[n + 1];

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            if (checkCycleIfAdded(u, v, adjList, n))
            {
                return {u, v};
            }
            else
            {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }

        return {};
    }
};

// Time Complexity: O(n^2), where n is the number of edges in the input graph, since we are iterating through all the edges and performing a breadth-first search for each edge to check for cycles.
// Space Complexity: O(n + e), where n is the number of vertices and e is