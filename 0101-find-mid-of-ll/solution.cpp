#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:

class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* curr = head;

        ListNode* mid = findMiddle(curr);
        ListNode* next = mid->next;
        while (curr && curr->next != mid) {
            curr = curr->next;
        }
        curr->next = next;
        return head;
    }
};