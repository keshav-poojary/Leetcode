#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();

        // process first k elements
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        // process remaining elements
        for (int i = k; i < n; i++)
        {

            // if current max is outside of window, remove the current maxes
            while (!dq.empty() && dq.front() <= (i - k))
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// Time Complexity: O(n), where n is the length of the input array nums. Each element is processed at most twice (once when it is added to the deque and once when it is removed).
// Space Complexity: O(k), where k is the size of the sliding window. In the worst case, the deque can hold all elements in the current window.