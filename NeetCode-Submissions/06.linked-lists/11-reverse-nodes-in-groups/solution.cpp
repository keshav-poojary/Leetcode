#include <bits/stdc++.h>
using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *cursor = head;
        if (!head)
        {
            return NULL;
        }

        for (int i = 0; i < k; i++)
        {
            if (cursor == NULL)
            {
                return head;
            }
            cursor = cursor->next;
        }

        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *fwd = NULL;

        int count = 0;

        while (curr != NULL && count != k)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            count++;
        }

        if (fwd != NULL)
        {
            head->next = reverseKGroup(fwd, k);
        }

        return prev;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the linked list.
// Space Complexity: O(N/k) where N is the number of nodes in the linked list