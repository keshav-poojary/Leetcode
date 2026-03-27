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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};  
class Solution {
public:
    void inorder(TreeNode*& root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    void buildTree(TreeNode*& root, int low, int high, vector<int>& res) {
        if (low > high) {
            return;
        }

        int mid = (low + high) / 2;
        root = new TreeNode(res[mid]);
        buildTree(root->left, low, mid - 1, res);
        buildTree(root->right, mid + 1, high, res);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        int low = 0;
        int high = res.size() - 1;
        int mid = (low + high) / 2;
        TreeNode* newroot = new TreeNode(res[mid]);
        buildTree(newroot->left, low, mid - 1, res);
        buildTree(newroot->right, mid + 1, high, res);
        return newroot;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the binary tree. 
// Space Complexity: O(n) in the worst case when the binary tree is skewed.