#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;

        vector<int> adjList[n];
        queue<int> q;

        for (auto it : prerequisites)
        {
            // u->v, [ai,bi] -> complete bi before ai
            adjList[it[1]].push_back(it[0]);
        }

        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto ngbr : adjList[i])
            {
                inDegree[ngbr]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty())
        {
            auto top = q.front();
            topo.push_back(top);
            q.pop();

            for (auto ngbr : adjList[top])
            {
                inDegree[ngbr]--;
                if (inDegree[ngbr] == 0)
                {
                    q.push(ngbr);
                }
            }
        }

        return topo.size() == n;
    }
};

// Time Complexity: O(V + E), where V is the number of courses (vertices) and E is the number of prerequisites (edges), since we are performing a topological sort using Kahn's algorithm.
// Space Complexity: O(V + E), where V is the number of courses (vertices) and E is the number of prerequisites (edges), since we are storing the adjacency list and in-degree array.