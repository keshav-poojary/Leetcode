#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findCycle(int node, vector<int> adjList[], vector<int> &vis)
    {
        vis[node] = 1;
        map<int, int> childToParentMapping;
        queue<int> q;

        childToParentMapping[node] = -1;
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
                    childToParentMapping[ngbr] = curr;
                    q.push(ngbr);
                }
                else if (vis[ngbr] && childToParentMapping[curr] != ngbr)
                {
                    return true;
                }
            }
        }

        return false;
    }
    bool isTree(int n, int m, vector<vector<int>> &edges)
    {
        // code here
        vector<int> adjList[n];

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n + 1, 0);
        bool isCycle = false;
        bool isConnected = true;

        if (findCycle(0, adjList, vis))
            isCycle = true;

        // check for connectivity
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                isConnected = false;
            }
        }

        if (!isCycle && isConnected)
        {
            return true;
        }

        return false;
    }
};

// Time Complexity: O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph, since we are performing a breadth-first search to detect cycles and check connectivity.
// Space Complexity: O(V + E), where V is the number of vertices (nodes)
