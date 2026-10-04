#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        map<Node *, Node *> mp;
        queue<Node *> q;

        // Edge case1: if not nodes
        if (!node)
        {
            return NULL;
        }

        // Edge case2: if only one node
        if (node->neighbors.size() == 0)
        {
            return new Node(node->val);
        }

        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            for (auto ngbr : top->neighbors)
            {
                if (mp.find(ngbr) == mp.end())
                {
                    mp[ngbr] = new Node(ngbr->val);
                    q.push(ngbr);
                }

                mp[top]->neighbors.push_back(mp[ngbr]);
            }
        }

        return mp[node];
    }
};

// Time Complexity: O(n + e), where n is the number of nodes and e is the number of edges in the graph, since we are iterating through all the nodes and edges once.
// Space Complexity: O(n), where n is the number of nodes in the graph, since