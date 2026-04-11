#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return head;
        }

        Node *curr = head;

        // Step 1 : Insert new Nodes in between
        while (curr != NULL)
        {
            Node *temp = curr->next;
            Node *newNode = new Node(curr->val);
            curr->next = newNode;
            newNode->next = temp;
            curr = curr->next->next;
        }

        curr = head;
        // Step 2: create random pointers on cloned list
        while (curr != NULL)
        {
            if (curr->random)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step3 : Remove links
        Node *ans = head->next;
        Node *temp = ans;
        curr = head;
        while (curr != NULL)
        {
            curr->next = temp->next;
            curr = curr->next;
            if (!curr)
                break;
            temp->next = curr->next;
            temp = temp->next;
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1) (excluding the space for the new nodes)