
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;

        for (auto stone : stones)
        {
            pq.push(stone);
        }

        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            if (pq.size() == 0)
            {
                if (a == b)
                {
                    return 0;
                }
            }

            if (a == b)
            {
                continue;
            }
            else
            {
                pq.push(abs(b - a));
            }
        }

        return pq.top();
    }
};

// Time Complexity: O(nlogn) for sorting the stones and O(nlogn) for the while loop
// Space Complexity: O(n) for the priority queue