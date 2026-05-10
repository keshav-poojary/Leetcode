#include <iostream>
using namespace std;

class ListNode
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
    ListNode *findMiddle(ListNode *head)
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

    ListNode *obtainReverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    void reorderList(ListNode *head)
    {
        ListNode *first = head;
        ListNode *middle = findMiddle(head);
        ListNode *second = obtainReverse(middle->next);
        middle->next = NULL;

        ListNode *dummy = new ListNode(0);
        dummy->next = NULL;
        ListNode *curr = dummy;

        while (first || second)
        {
            if (first)
            {
                curr->next = first;
                first = first->next;
                curr = curr->next;
            }

            if (second)
            {
                curr->next = second;
                second = second->next;
                curr = curr->next;
            }
        }

        head = dummy->next;
    }
};