
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
    bool isValid(TreeNode *root, long long mini, long long maxi)
    {
        if (!root)
        {
            return true;
        }

        if (root->val <= mini || root->val >= maxi)
        {
            return false;
        }

        bool left = isValid(root->left, mini, root->val);
        bool right = isValid(root->right, root->val, maxi);

        return left && right;
    }
    bool isValidBST(TreeNode *root)
    {
        long mini = LLONG_MIN;
        long maxi = LLONG_MAX;
        if (root && root->left == NULL && root->right == NULL)
        {
            return true;
        }
        return isValid(root, mini, maxi);
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are traversing the binary tree once and visiting each node once.
// Space Complexity: O(H) where H is the height of the binary tree. In the