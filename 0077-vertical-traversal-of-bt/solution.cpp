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
    void traverse(TreeNode *root, map<int, vector<pair<int, int>>> &mp)
    {
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto top = q.front();
                TreeNode *node = top.first;
                int hd = top.second.first;
                int level = top.second.second;
                q.pop();

                mp[hd].push_back({level, node->val});

                if (node->left)
                {
                    q.push({node->left, {hd - 1, level + 1}});
                }

                if (node->right)
                {
                    q.push({node->right, {hd + 1, level + 1}});
                }
            }
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;
        map<int, vector<pair<int, int>>> mp;
        traverse(root, mp);
        for (auto it : mp)
        {
            // sort by level

            sort(it.second.begin(), it.second.end());
            vector<int> ans;
            // insert the values
            for (int i = 0; i < it.second.size(); i++)
            {
                ans.push_back(it.second[i].second);
            }
            res.push_back(ans);
            ans.clear();
        }

        return res;
    }
};

//  time complexity: O(n log n) where n is the number of nodes in the binary tree, due to sorting the nodes at each horizontal distance
// space complexity: O(n) in the worst case when all nodes are at the same horizontal