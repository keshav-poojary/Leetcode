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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> data;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *head = lists[i];
            ListNode *curr = head;
            while (curr != NULL)
            {
                data.push_back(curr->val);
                curr = curr->next;
            }
        }

        sort(data.begin(), data.end());
        ListNode *dummy = new ListNode(-1);
        dummy->next = NULL;
        ListNode *curr = dummy;
        for (int i = 0; i < data.size(); i++)
        {
            ListNode *newNode = new ListNode(data[i]);
            curr->next = newNode;
            curr = curr->next;
        }

        return dummy->next;
    }
};

// Time Complexity: O(NlogN) where N is the total number of nodes in all the linked lists.
// Space Complexity: O(N) where N is the total number of nodes in all the linked lists.