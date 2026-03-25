#include <bits/stdc++.h>
using namespace std;
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

 class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    bool dfs(TreeNode* root, int sum, int targetSum) {
        if (!root) {
            return false;
        }

        //preorder traversal

        sum = sum + root->val;

        if (root->left == NULL && root->right == NULL && sum == targetSum) {
            return true;
        }

        bool left =  dfs(root->left, sum, targetSum);
        bool right = dfs(root->right, sum, targetSum);

        return left || right; 
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;

        return dfs(root, sum, targetSum);
    }
};

// Time Complexity: O(n) where n is the number of nodes in the binary tree.
// Space Complexity: O(n) in the worst case when the binary tree is a complete binary