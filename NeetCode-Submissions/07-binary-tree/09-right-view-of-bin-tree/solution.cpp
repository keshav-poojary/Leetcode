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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *top = q.front();
                q.pop();

                if (i == size - 1)
                {
                    ans.push_back(top->val);
                }

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

        return ans;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are traversing the binary tree level by level and visiting each node once.
// Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are storing the values of the nodes in a vector and the maximum number of nodes at any level can be N/2, which is O(N).