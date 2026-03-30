
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};