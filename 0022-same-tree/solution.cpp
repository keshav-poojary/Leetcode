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

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }

        if (p && !q || q && !p)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        int left = isSameTree(p->left, q->left);
        int right = isSameTree(p->right, q->right);

        return left && right;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the binary tree.
// Space Complexity: O(n) in the worst case when the binary tree is a complete binary