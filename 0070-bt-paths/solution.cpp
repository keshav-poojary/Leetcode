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
    void traverse(TreeNode *root, vector<string> &ans, string path)
    {
        if (root == NULL)
            return;

        if (!root->left && !root->right && root)
        {
            path = path + to_string(root->val);
            ans.push_back(path);
            return;
        }

        path = path + to_string(root->val);
        path = path + "->";

        traverse(root->left, ans, path);
        traverse(root->right, ans, path);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        if (!root)
        {
            return ans;
        }
        traverse(root, ans, "");
        return ans;
    }
};