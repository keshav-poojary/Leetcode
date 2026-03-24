/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public: 
    int data;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int maxi = INT_MIN;

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            level++;
            while (size--) {
                TreeNode* top = q.front();
                q.pop();

                if (top->left == NULL && top->right == NULL) {
                    maxi = max(maxi, level);
                }

                if (top->left) {
                    q.push(top->left);
                }

                if (top->right) {
                    q.push(top->right);
                }
            }
        }

        return maxi;
    }
};