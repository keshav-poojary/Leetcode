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
            return NULL;
        }

        Node *curr = head;

        // step 1: add new nodes in between
        while (curr != NULL)
        {
            Node *temp = curr->next;
            Node *newNode = new Node(curr->val);
            curr->next = newNode;
            newNode->next = temp;
            curr = curr->next->next;
        }

        curr = head;
        // step 2:  add random links
        while (curr != NULL)
        {
            if (curr->random)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // step 3: unlink
        curr = head;
        Node *clonedAnswer = curr->next;
        Node *curr2 = head->next;

        while (curr != NULL)
        {
            curr->next = curr->next->next;
            if (curr2->next)
                curr2->next = curr2->next->next;
            curr = curr->next;
            curr2 = curr2->next;
        }

        return clonedAnswer;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) since we are using only a constant amount of extra space.