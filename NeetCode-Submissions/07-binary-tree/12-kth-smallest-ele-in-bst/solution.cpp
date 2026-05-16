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
    void inorder(TreeNode *root, vector<int> &inres)
    {
        if (!root)
        {
            return;
        }

        inorder(root->left, inres);
        inres.push_back(root->val);
        inorder(root->right, inres);
    }
    int kthSmallest(TreeNode *root, int k)
    {

        vector<int> inres;
        inorder(root, inres);
        return inres[k - 1];
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are traversing the binary tree once and visiting each node once.
// Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are storing the values of the nodes in a vector and the maximum number of nodes at any level can be N/2, which is O(N).