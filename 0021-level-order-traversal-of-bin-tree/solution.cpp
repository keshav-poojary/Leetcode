#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class TreeNode{
    public: 
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (!root)
        {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            while (size--)
            {
                TreeNode *top = q.front();
                q.pop();

                temp.push_back(top->val);

                if (top->left)
                {
                    q.push(top->left);
                }

                if (top->right)
                {
                    q.push(top->right);
                }
            }

            res.push_back(temp);
            temp.clear();
        }

        return res;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the binary tree.
// Space Complexity: O(n) in the worst case when the binary tree is a complete binary