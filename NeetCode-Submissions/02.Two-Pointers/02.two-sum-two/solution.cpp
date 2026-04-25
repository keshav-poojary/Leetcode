#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int low = 0;
        int high = numbers.size() - 1;

        while (low < high)
        {
            if (numbers[low] + numbers[high] == target)
            {
                return {low + 1, high + 1};
            }
            else if (numbers[low] + numbers[high] > target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }

        return {};
    }
};

// Time Complexity: O(n) where n is the number of elements in the input array, since we may need to iterate through the array once in the worst case
// Space Complexity: O(1) since we are using only a constant amount of extra space