#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                      vector<vector<int>> &queries)
    {
        vector<int> components(n, 0);
        int val = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] > maxDiff)
            {
                val++;
            }
            components[i] = val;
        }

        vector<bool> res;
        for (auto query : queries)
        {
            int source = query[0];
            int dest = query[1];
            res.push_back(components[source] == components[dest]);
        }

        return res;
    }
};

// time complexity: O(n + q), where n is the size of nums and q is the number of queries

// components are connected components of the graph, if two nodes belong to the same component, then there is a path between them.
// space complexity: O(n + q), where n is the size of nums and q is the number of queries
