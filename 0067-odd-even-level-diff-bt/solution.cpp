#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
        // Your code here
        int oddSum = 0;
        int evenSum = 0;

        int level = 0;
        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            level++;
            while (size--)
            {
                Node *top = q.front();
                q.pop();

                if (level % 2 == 0)
                {
                    evenSum = evenSum + top->data;
                }
                else
                {
                    oddSum = oddSum + top->data;
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

        return oddSum - evenSum;
    }
};

// time complexity: O(n) where n is the number of nodes in the binary tree
// space complexity: O(w) where w is the maximum width of the binary tree