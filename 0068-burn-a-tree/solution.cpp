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
    TreeNode *
    createChildToParentMap(map<TreeNode *, TreeNode *> &childToParentMap,
                           TreeNode *&root, int start)
    {
        if (!root)
        {
            return NULL;
        }
        queue<TreeNode *> q;
        q.push(root);
        childToParentMap[root] = NULL;
        TreeNode *target = NULL;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto top = q.front();
                q.pop();

                if (top->val == start)
                {
                    target = top;
                }

                if (top->left)
                {
                    childToParentMap[top->left] = top;
                    q.push(top->left);
                }

                if (top->right)
                {
                    childToParentMap[top->right] = top;
                    q.push(top->right);
                }
            }
        }

        return target;
    }

    int burnTree(map<TreeNode *, TreeNode *> &childToParentMap,
                 TreeNode *target)
    {
        map<TreeNode *, bool> visited;
        queue<TreeNode *> q;

        q.push(target);
        visited[target] = 1;
        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            int flag = 0;
            while (size--)
            {
                auto top = q.front();
                q.pop();

                if (top->left && !visited[top->left])
                {
                    flag = 1;
                    q.push(top->left);
                    visited[top->left] = 1;
                }

                if (top->right && !visited[top->right])
                {
                    flag = 1;
                    q.push(top->right);
                    visited[top->right] = 1;
                }

                if (childToParentMap[top] && !visited[childToParentMap[top]])
                {
                    flag = 1;
                    q.push(childToParentMap[top]);
                    visited[childToParentMap[top]] = 1;
                }
            }
            if (flag)
            {
                time++;
            }
        }

        return time;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        map<TreeNode *, TreeNode *> childToParentMap;
        TreeNode *targetNode = NULL;
        int time = 0;
        targetNode = createChildToParentMap(childToParentMap, root, start);
        time = burnTree(childToParentMap, targetNode);
        return time;
    }
};