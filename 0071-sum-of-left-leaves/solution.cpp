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
    void traverse(TreeNode *root, int &sum)
    {
        if (!root)
        {
            return;
        }

        if (root && root->left)
        {
            if (root->left->left == NULL && root->left->right == NULL)
            {
                sum = sum + root->left->val;
            }
        }

        traverse(root->left, sum);
        traverse(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        traverse(root, sum);
        return sum;
    }
};