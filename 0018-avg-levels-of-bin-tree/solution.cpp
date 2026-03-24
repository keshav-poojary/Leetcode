// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  *

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> res;
        vector<double> ans;

        if (!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<int> arr;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* data = q.front();

                q.pop();
                arr.push_back(data->val);

                if (data->left) {
                    q.push(data->left);
                }

                if (data->right) {
                    q.push(data->right);
                }
            }

            res.push_back(arr);
            arr.clear();
        }

        for (auto arr : res) {
            double sum = 0;
            for (int i = 0; i < arr.size(); i++) {
                sum = sum + arr[i];
            }
            ans.push_back(double(sum / arr.size()));
        }

        return ans;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the binary tree.
// Space Complexity: O(n) in the worst case when the binary tree is a complete binary