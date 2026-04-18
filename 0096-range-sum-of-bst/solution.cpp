#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class Solution
{
public:
    void inorder(TreeNode *root, int low, int high, int &sum)
    {
        if (!root)
        {
            return;
        }
        if (root->val <= high && root->val >= low)
        {
            sum = sum + root->val;
        }
        inorder(root->left, low, high, sum);
        inorder(root->right, low, high, sum);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        inorder(root, low, high, sum);
        return sum;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n) in worst case (skewed tree), O(log(n)) in best case (balanced tree))