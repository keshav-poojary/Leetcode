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

#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    void buildTree(TreeNode *&root, int low, int high, vector<int> &nums)
    {
        if (low > high)
        {
            return;
        }

        int mid = (low + (high - low) / 2);
        root = new TreeNode(nums[mid]);
        buildTree(root->left, low, mid - 1, nums);
        buildTree(root->right, mid + 1, high, nums);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return NULL;
        }

        if (nums.size() == 1)
        {
            return new TreeNode(nums[0]);
        }

        int low = 0;
        int high = nums.size() - 1;
        int mid = (low + high) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        buildTree(root->left, low, mid - 1, nums);
        buildTree(root->right, mid + 1, high, nums);

        return root;
    }
};

// Time Complexity: O(n) where n is the number of elements in the input array.
// Space Complexity: O(n) in the worst case when the binary tree is skewed.