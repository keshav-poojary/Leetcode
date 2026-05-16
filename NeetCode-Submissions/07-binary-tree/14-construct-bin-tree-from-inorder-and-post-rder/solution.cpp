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
    TreeNode *solve(vector<int> &inorder,
                    vector<int> &postorder,
                    int &postOrderIndex,
                    int inorderStart,
                    int inorderEnd)
    {

        if (postOrderIndex < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = postorder[postOrderIndex--];

        TreeNode *root = new TreeNode(element);

        int position = 0;

        for (int i = inorderStart; i <= inorderEnd; i++)
        {
            if (inorder[i] == element)
            {
                position = i;
                break;
            }
        }

        // Build right subtree first
        root->right = solve(inorder, postorder,
                            postOrderIndex,
                            position + 1,
                            inorderEnd);

        root->left = solve(inorder, postorder,
                           postOrderIndex,
                           inorderStart,
                           position - 1);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder,
                        vector<int> &postorder)
    {

        int n = postorder.size();

        int postOrderIndex = n - 1;

        return solve(inorder, postorder,
                     postOrderIndex,
                     0,
                     n - 1);
    }
};

// Time Complexity: O(N^2) where N is the number of nodes in the binary tree. This is because for each node, we are searching for its position in the inorder traversal, which takes O(N) time.
// Space Complexity: O(N) where N is the number of nodes in the binary tree.