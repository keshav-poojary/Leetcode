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

class Solution {
public:
    int height(TreeNode* root) {
        if(!root){
            return 0;
        }

        return max(height(root->left), height(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        int op1 = diameterOfBinaryTree(root->left);
        int op2 =  diameterOfBinaryTree(root->right);
        int op3 = height(root->left) + height(root->right);

        return max(op1, max(op2,op3));
    }
};

// Time Complexity: O(n) where n is the number of nodes in the binary tree.
// Space Complexity: O(n) in the worst case when the binary tree is a complete binary