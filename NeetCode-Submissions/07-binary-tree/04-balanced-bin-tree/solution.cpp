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
    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        return max(height(root->left) + 1, height(root->right) + 1);
    }

    bool traverse(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        if (abs(height(root->left) - height(root->right)) > 1)
        {
            return false;
        }

        return traverse(root->left) && traverse(root->right);
    }
    bool isBalanced(TreeNode *root) { return traverse(root); }
};