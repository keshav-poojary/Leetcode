#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];

            if (mp.find(sum - k) != mp.end())
            {
                count = count + mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// Note: This solution works for both positive and negative numbers in the array.
// The previous solution using sliding window only works for positive numbers.
//  The idea is to use a hash map to store the prefix sums and their frequencies.
//  We iterate through the array and keep track of the current prefix sum.
//  For each prefix sum, we check if there is a prefix sum that is equal to the current prefix sum minus k.
//  If there is, then we can add the frequency of that prefix sum to our count
//  because it means that there is a subarray that sums to k between those two prefix sums.
