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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return new TreeNode(val);
        }

        TreeNode *current = root;
        TreeNode *parent = NULL;

        while (current != NULL)
        {
            if (current->val > val)
            {
                parent = current;
                current = current->left;
            }
            else
            {
                parent = current;
                current = current->right;
            }
        }

        if (current == NULL)
        {
            if (parent->val > val)
            {
                parent->left = new TreeNode(val);
            }
            else
            {
                parent->right = new TreeNode(val);
            }
        }

        return root;
    }
};
// Time Complexity: O(h) where h is the height of the binary search tree.
// Space Complexity: O(1) since we are not using any extra space.

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return new TreeNode(val);
        }

        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};

// Time Complexity: O(h) where h is the height of the binary search tree.
// Space Complexity: O(h) in the worst case when the binary search tree is skewed.

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
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *current = root;
        TreeNode *parent = NULL;

        while (current != NULL)
        {
            parent = current;
            if (current->val < val)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }

        if (parent == NULL)
        {
            return new TreeNode(val);
        }

        if (parent->val > val)
        {
            parent->left = new TreeNode(val);
        }
        else
        {
            parent->right = new TreeNode(val);
        }

        return root;
    }
};