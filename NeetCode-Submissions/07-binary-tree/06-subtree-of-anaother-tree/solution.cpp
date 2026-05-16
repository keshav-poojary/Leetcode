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
    bool isSame(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }

        if (!p || !q)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
        {
            return false;
        }

        if (isSame(root, subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

// Time Complexity: O(N*M) where N is the number of nodes in the binary tree and M is the number of nodes in the subtree. This is because for each node in the binary tree, we are checking if it is the same as the subtree, which takes O(M) time.
// Space Complexity: O(H) where H is the height of the binary tree. In the