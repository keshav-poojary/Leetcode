#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        for (int i = k; i <= nums.size() - 1; i++) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};

//time complexity: O(nlogk)
//space complexity: O(k)