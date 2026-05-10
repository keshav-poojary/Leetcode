
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = NULL;

        ListNode *pointerOne = list1;
        ListNode *pointerTwo = list2;
        ListNode *curr = dummy;

        while (pointerOne != NULL && pointerTwo != NULL)
        {
            if (pointerOne->val <= pointerTwo->val)
            {
                curr->next = pointerOne;
                pointerOne = pointerOne->next;
                curr = curr->next;
            }
            else
            {
                curr->next = pointerTwo;
                pointerTwo = pointerTwo->next;
                curr = curr->next;
            }
        }

        if (pointerOne != NULL)
        {
            curr->next = pointerOne;
        }
        else
        {
            curr->next = pointerTwo;
        }

        return dummy->next;
    }
};

// Time Complexity: O(n + m) where n and m are the number of nodes in list1 and list2 respectively.
// Space Complexity: O(1) since we are using only a constant amount of extra space