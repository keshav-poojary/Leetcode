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
    void preorder(TreeNode *root, int &count, int maxi)
    {
        if (!root)
        {
            return;
        }

        if (root->val >= maxi)
        {
            count++;
            maxi = root->val;
        }

        preorder(root->left, count, maxi);
        preorder(root->right, count, maxi);
    }
    int goodNodes(TreeNode *root)
    {
        int count = 0;
        int maxi = INT_MIN;
        preorder(root, count, maxi);
        return count;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are traversing the binary tree once and visiting each node once.
// Space Complexity: O(H) where H is the height of the binary tree. In the worst case, the binary tree can be skewed, and the height can be equal to the number of nodes in the binary tree. In the best case, the binary tree can be balanced, and the height can be logN where N is the number of nodes in the binary tree.
// Note: The space complexity can be O(N) in the worst case when the binary tree is skewed, and the height is equal to the number of nodes in the binary tree. In the best case, when the binary tree is balanced, the height can be logN, and the space complexity can be O(logN).
// The approach is to do a preorder traversal of the binary tree and keep track of the maximum value seen so far. If the current node's value is greater than or equal to the maximum value seen so far, then it is a good node, and we increment the count. We also update the maximum value seen so far to be the maximum of the current node's value and the maximum value seen so far. We then recursively call the preorder function for the left and right subtrees of the current node. Finally, we return the count of good nodes in the binary tree.