#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *findCycle(Node *head)
    {
        Node *fast = head;
        Node *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return slow;
            }
        }

        return NULL;
    }

    Node *findInterSectionNode(Node *middle, Node *head)
    {
        Node *curr = head;
        while (curr != middle)
        {
            curr = curr->next;
            middle = middle->next;
        }

        return curr;
    }

    void removeLoop(Node *head)
    {
        // code here
        Node *cycleNode = findCycle(head);

        if (!cycleNode)
        {
            return;
        }

        Node *loopNode = findInterSectionNode(cycleNode, head);

        Node *temp = loopNode;

        while (temp->next != loopNode)
        {
            temp = temp->next;
        }

        temp->next = NULL;
    }
};