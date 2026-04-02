#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = NULL;
        ListNode *curr = dummy;

        for (int i = 0; i < left; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        ListNode *subListStartNode = curr;
        ListNode *newPrev = NULL;

        for (int i = 0; i <= right - left; i++)
        {
            ListNode *temp = curr->next;
            curr->next = newPrev;
            newPrev = curr;
            curr = temp;
        }

        prev->next = newPrev;
        subListStartNode->next = curr;

        return dummy->next;
    }
};