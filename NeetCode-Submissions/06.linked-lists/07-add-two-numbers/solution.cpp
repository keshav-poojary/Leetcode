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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;

        int sum = 0;
        int carry = 0;

        ListNode *ans = new ListNode(0);
        ListNode *curr = ans;

        while (curr1 || curr2 || carry)
        {
            sum = carry;
            if (curr1)
            {
                sum = sum + curr1->val;
                curr1 = curr1->next;
            }

            if (curr2)
            {
                sum = sum + curr2->val;
                curr2 = curr2->next;
            }

            int digit = sum % 10;
            curr->next = new ListNode(digit);
            curr = curr->next;
            carry = sum / 10;
            sum = 0;
        }

        return ans->next;
    }
};

// Time Complexity: O(max(n, m)) where n and m are the number of nodes in l1 and l2 respectively.
// Space Complexity: O(max(n, m)) since we are creating a new linked list to