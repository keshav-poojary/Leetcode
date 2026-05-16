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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
        {
            return NULL;
        }

        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (right && left)
        {
            return root;
        }

        if (left == NULL)
        {
            return right;
        }
        else
        {
            return left;
        }
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are traversing the binary tree once to find the lowest common ancestor.
// Space Complexity: O(H) where H is the height of the binary tree. In the worst case, the binary tree can be skewed, and the height can be equal to the number of nodes in the binary tree. In the best case, the binary tree can be balanced, and the height can be logN where N is the number of nodes in the binary tree.