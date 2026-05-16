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
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int level = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            level++;
            while (size--)
            {
                TreeNode *top = q.front();
                q.pop();

                if (top->left)
                {
                    q.push(top->left);
                }

                if (top->right)
                {
                    q.push(top->right);
                }
            }
        }

        return level;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree.
// Space Complexity: O(N) where N is the number of nodes in the binary tree.