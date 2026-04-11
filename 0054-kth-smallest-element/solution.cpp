#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        // code here
        priority_queue<int> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        for (int j = k; j < arr.size(); j++)
        {
            if (arr[j] < pq.top())
            {
                pq.pop();
                pq.push(arr[j]);
            }
        }

        return pq.top();
    }
};

// Time Complexity: O(n log k)
// Space Complexity: O(k)