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
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &index,
                    int inorderStart, int inorderEnd, int n)
    {
        if (index >= n)
        {
            return NULL;
        }

        if (inorderStart > inorderEnd)
        {
            return NULL;
        }

        int ele = preorder[index];
        TreeNode *node = new TreeNode(ele);
        index++;

        int pos = 0;
        for (int i = 0; i <= inorder.size(); i++)
        {
            if (inorder[i] == ele)
            {
                pos = i;
                break;
            }
        }

        node->left = solve(preorder, inorder, index, inorderStart, pos - 1, n);
        node->right = solve(preorder, inorder, index, pos + 1, inorderEnd, n);

        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preOrderIndex = 0;
        int n = preorder.size();
        return solve(preorder, inorder, preOrderIndex, 0, n - 1, n);
    }
};

// Time Complexity: O(N^2) where N is the number of nodes in the binary tree. This is because for each node, we are searching for its position in the inorder traversal, which takes O(N) time.
// Space Complexity: O(N) where N is the number of nodes in the binary tree.