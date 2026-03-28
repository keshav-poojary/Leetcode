/*
// Definition for a Node.
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
*/
#include<bits/stdc++.h>
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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mp;
        queue<Node*> q;

        if (!node) {
            return NULL;
        }

        if (node->neighbors.size() == 0) {
            return new Node(node->val);
        }

        q.push(node);

        Node* new_node = new Node(node->val);
        mp[node] = new_node;

        while (!q.empty()) {
            Node* top = q.front();
            q.pop();
            for (auto ngbr : top->neighbors) {
                if (mp.find(ngbr) == mp.end()) {
                    mp[ngbr] = new Node(ngbr->val);
                    q.push(ngbr);
                }
                mp[top]->neighbors.push_back(mp[ngbr]);
            }
        }

        return mp[node];
    }
};