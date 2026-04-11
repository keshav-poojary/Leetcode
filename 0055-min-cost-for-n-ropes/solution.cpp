#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        // code here
        int cost = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        // put all elements in min queue
        for (int i = 0; i < arr.size(); i++)
        {
            pq.push(arr[i]);
        }

        // process queue
        while (pq.size() > 1)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int result = first + second;
            cost = cost + result;
            pq.push(result);
        }

        return cost;
    }
};

// Time Complexity: O(n log n)
// Space Complexity: O(n)