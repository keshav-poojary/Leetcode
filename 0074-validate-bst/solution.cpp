#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    bool validateBST(TreeNode *root, long long min, long long max)
    {
        if (!root)
        {
            return true;
        }

        if (root->val >= max || root->val <= min)
        {
            return false;
        }

        bool left = validateBST(root->left, min, root->val);
        bool right = validateBST(root->right, root->val, max);

        return left && right;
    }
    bool isValidBST(TreeNode *root)
    {
        if (root && root->left == NULL && root->right == NULL)
        {
            return true;
        }

        return validateBST(root, LLONG_MIN, LLONG_MAX);
    }
};

// time complexity: O(n) where n is the number of nodes in the binary tree
// space complexity: O(h) in the worst case when the binary tree is skewed,