#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void findciel(Node *root, int k, int &ans)
    {
        if (!root)
        {
            return;
        }

        if (root->data == k)
        {
            ans = k;
            return;
        }

        if (k > root->data)
        {
            findciel(root->right, k, ans);
        }
        else
        {
            ans = root->data;
            findciel(root->left, k, ans);
        }
    }

    int findCeil(Node *root, int k)
    {
        int ans = -1;
        findciel(root, k, ans);
        return ans;
    }
};

// time complexity: O(h) where h is the height of the binary search tree
// space complexity: O(h) in the worst case when the binary search tree is skewed
