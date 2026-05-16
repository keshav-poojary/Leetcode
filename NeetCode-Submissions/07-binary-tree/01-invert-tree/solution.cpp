#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    void invert(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        TreeNode *val = root->right;
        root->right = root->left;
        root->left = val;
        invert(root->left);
        invert(root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        invert(root);
        return root;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree.
// Space Complexity: O(H) where H is the height of the binary tree. In the