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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        queue<TreeNode *> q;
        q.push(root);
        long long sum = 0;
        vector<long long> ans;

        while (!q.empty())
        {
            auto size = q.size();
            sum = 0;
            while (size--)
            {
                auto top = q.front();
                sum = sum + top->val;
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
            ans.push_back(sum);
        }

        if (k > ans.size())
            return -1;

        sort(ans.begin(), ans.end(), greater<long long>());

        return ans[k - 1];
    }
};