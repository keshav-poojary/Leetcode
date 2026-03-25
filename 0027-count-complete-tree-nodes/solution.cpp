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
    void inorder(TreeNode* root, int& count) {
        if (!root) {
            return;
        }

        count = count + 1;
        inorder(root->left, count);
        inorder(root->right, count);
    }

    int countNodes(TreeNode* root) {
        int count = 0;
        if (!root) {
            return 0;
        }

        inorder(root, count);
        return count;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the binary tree. 
// Space Complexity: O(n) in the worst case when the binary tree is a complete binary