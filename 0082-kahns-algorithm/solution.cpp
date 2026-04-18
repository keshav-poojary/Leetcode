#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // step1 : create adjacency list
        vector<int> adj[V];

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        // step 2: create indegree list
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto ngbr : adj[i])
            {
                indegree[ngbr]++;
            }
        }
        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int data = q.front();
            q.pop();
            ans.push_back(data);

            for (auto ngbr : adj[data])
            {
                indegree[ngbr]--;
                if (indegree[ngbr] == 0)
                {
                    q.push(ngbr);
                }
            }
        }

        return ans;
    }
};

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)