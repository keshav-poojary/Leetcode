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
class Codec
{
public:
    // Encodes a tree to a single string.
    void preOrderSerialize(TreeNode *root, string &s)
    {
        if (!root)
        {
            s = s + "#,";
            return;
        }
        s = s + to_string(root->val) + ",";
        preOrderSerialize(root->left, s);
        preOrderSerialize(root->right, s);
    }
    string serialize(TreeNode *root)
    {
        string s = "";
        preOrderSerialize(root, s);
        return s;
    }

    TreeNode *solve(vector<string> &data, int &index, int n)
    {
        if (index >= n)
        {
            return NULL;
        }

        if (data[index] == "#")
        {
            index++;
            return NULL;
        }

        TreeNode *newNode = new TreeNode(stoi(data[index]));
        index++;

        newNode->left = solve(data, index, n);
        newNode->right = solve(data, index, n);

        return newNode;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int index = 0;
        vector<string> nodes;
        string temp = "";

        for (char ch : data)
        {
            if (ch == ',')
            {
                nodes.push_back(temp);
                temp = "";
            }
            else
            {
                temp += ch;
            }
        }
        int n = nodes.size();
        return solve(nodes, index, n);
    }
};

// time complexity: O(N) where N is the number of nodes in the binary tree. This is because we are traversing the binary tree once to serialize it and once to deserialize it.
// space complexity: O(N) where N is the number of nodes in the binary tree.