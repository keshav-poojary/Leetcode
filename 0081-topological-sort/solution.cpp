#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, stack<int> &st, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;

        for (auto ngbr : adj[node])
        {
            if (!vis[ngbr])
            {
                dfs(ngbr, st, adj, vis);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<int> res;
        stack<int> st;

        vector<int> adj[V];

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, st, adj, vis);
            }
        }

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};