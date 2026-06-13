
#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        for (auto num : nums)
        {
            add(num);
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > K)
        {
            pq.pop();
        }

        return pq.top();
    }
};

// Time Complexity: O(logK) for add() and O(K) for constructor
// Space Complexity: O(K) for the priority queue