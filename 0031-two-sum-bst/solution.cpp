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
    bool preorderTraversal(TreeNode *root, int k, set<int> &s)
    {
        if (!root)
        {
            return false;
        }

        if (s.find(k - root->val) != s.end())
        {
            return true;
        }

        s.insert(root->val);
        return preorderTraversal(root->left, k, s) ||
               preorderTraversal(root->right, k, s);
    }
    bool findTarget(TreeNode *root, int k)
    {
        set<int> s;
        return preorderTraversal(root, k, s);
    }
};

// Time Complexity: O(n) where n is the number of nodes in the binary tree.
// Space Complexity: O(n) in the worst case when the binary tree is skewed and