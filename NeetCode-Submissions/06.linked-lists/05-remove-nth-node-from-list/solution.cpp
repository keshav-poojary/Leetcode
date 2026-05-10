#include <bits/stdc++.h>
using namespace std;

class
    ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    int calculateLength(ListNode *head)
    {
        ListNode *curr = head;
        int length = 0;
        while (curr != NULL)
        {
            length++;
            curr = curr->next;
        }

        return length;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = calculateLength(head);
        int toDelete = length - n;
        if (n == length)
        {
            return head->next;
        }

        ListNode *curr = head;

        while (toDelete)
        {
            toDelete--;
            if (toDelete > 0)
            {
                curr = curr->next;
            }
            else
            {
                curr->next = curr->next->next;
            }
        }

        return head;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) since we are using only a constant amount of extra space.