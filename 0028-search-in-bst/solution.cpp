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

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) {
            return NULL;
        }

        if (root->val == val) {
            return root;
        }

        if (root->val < val) {
            return searchBST(root->right, val);
        }

        return searchBST(root->left, val);
    }
};

// Time Complexity: O(h) where h is the height of the binary search tree.
// Space Complexity: O(h) in the worst case when the binary search tree is skewed