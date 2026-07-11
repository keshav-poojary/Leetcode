#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        map<int, vector<int>> adjList;
        vector<bool> visited(n, false);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        queue<int> q;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            q.push(i);
            vector<int> comp;

            while (!q.empty())
            {
                int src = q.front();
                q.pop();
                comp.push_back(src);

                for (auto ngbr : adjList[src])
                {
                    if (!visited[ngbr])
                    {
                        q.push(ngbr);
                        visited[ngbr] = true;
                    }
                }
            }

            long long degreeSum = 0;
            for (auto u : comp)
            {
                degreeSum += adjList[u].size();
            }

            long long k = comp.size();
            if (degreeSum / 2 == k * (k - 1) / 2)
            {
                ans++;
            }
        }

        return ans;
    }
};

// Time Complexity: O(n + e) where n is the number of vertices and e is the number of edges
// Space Complexity: O(n + e) for the adjacency list and visited array