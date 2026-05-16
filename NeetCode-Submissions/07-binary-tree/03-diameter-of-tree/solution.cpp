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
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->left) + height(root->right);

        return max(op1, max(op2, op3));
    }
};

// Time Complexity: O(N^2) where N is the number of nodes in the binary tree. This is because for each node, we are calculating the height of its left and right subtrees, which takes O(N) time.
// Space Complexity: O(H) where H is the height of the binary tree. In the