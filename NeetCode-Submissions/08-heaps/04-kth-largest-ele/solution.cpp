#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq; // minheap

        for (int i = 0; i < nums.size(); i++)
        {
            if (i < k)
            {
                pq.push(nums[i]);
            }
            else
            {
                if (nums[i] > pq.top())
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }

        return pq.top();
    }
};

// Time Complexity: O(nlogK) for iterating through the numbers and maintaining the priority queue
// Space Complexity: O(K) for the priority queue