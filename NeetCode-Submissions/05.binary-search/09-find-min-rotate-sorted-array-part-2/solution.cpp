#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mini = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                mini = min(mini, nums[low]);
                low++;
                high--;
                continue;
            }
            if (nums[low] <= nums[mid] && nums[mid] <= nums[high])
            {
                mini = min(mini, nums[low]);
                mini = min(mini, nums[mid]);
                low = mid + 1;
                high = mid - 1;
            }
            else if (nums[mid] > nums[high] && nums[low] <= nums[mid])
            {
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            else if (nums[mid] <= nums[high] && nums[low] > nums[mid])
            {
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }

        return mini;
    }
};

// Time Complexity: O(logN) where N is the number of elements in the input array.
// Space Complexity: O(1) as we are not using any extra space.