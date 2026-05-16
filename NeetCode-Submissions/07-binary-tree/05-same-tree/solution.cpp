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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        if (!p && !q)
        {
            return true;
        }

        if (p && !q)
        {
            return false;
        }

        if (q && !p)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        bool right = isSameTree(p->right, q->right);
        bool left = isSameTree(p->left, q->left);

        return right && left;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are traversing both trees simultaneously and comparing each node.
// Space Complexity: O(H) where H is the height of the binary tree. In the