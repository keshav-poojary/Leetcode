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
    void inorder(TreeNode *root, int &mini, int &prev)
    {
        if (!root)
        {
            return;
        }

        inorder(root->left, mini, prev);

        if (prev != INT_MAX)
        {
            mini = min(mini, abs(prev - root->val));
        }
        prev = root->val;

        inorder(root->right, mini, prev);
    }

    int getMinimumDifference(TreeNode *root)
    {
        int mini = INT_MAX;
        int prevMini = INT_MAX;
        inorder(root, mini, prevMini);
        return mini;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the binary tree.
// Space Complexity: O(n) in the worst case when the binary tree is skewed.