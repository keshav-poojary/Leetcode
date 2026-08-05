#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>> &invocations)
    {

        vector<int> ans;
        vector<pair<int, int>> adj;
        map<int, vector<int>> adjList;

        for (auto inv : invocations)
        {
            pair<int, int> p = make_pair(inv[0], inv[1]);
            adj.push_back(p);
        }

        for (auto inv : invocations)
        {
            adjList[inv[0]].push_back(inv[1]);
        }

        queue<int> q;
        q.push(k);
        set<int> s;
        s.insert(k);
        int suspiciousSize = s.size();

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (auto ngbr : adjList[top])
            {
                if (s.find(ngbr) == s.end())
                {
                    s.insert(ngbr);
                    q.push(ngbr);
                }
            }
        }

        bool canRemove = true;
        for (auto ele : adj)
        {
            int u = ele.first;
            int v = ele.second;
            if (s.find(u) == s.end() && s.find(v) != s.end())
            {
                canRemove = false;
                break;
            }
        }

        if (!canRemove)
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(i);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (s.find(i) == s.end())
                {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};