#include <bits/stdc++.h>
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
    int pairSum(ListNode *head)
    {
        vector<int> res;

        while (head != NULL)
        {
            res.push_back(head->val);
            head = head->next;
        }

        int start = 0;
        int end = res.size() - 1;
        int maxi = INT_MIN;
        while (start <= end)
        {
            int sum = res[start] + res[end];
            maxi = max(maxi, sum);
            start++;
            end--;
        }

        return maxi;
    }
};