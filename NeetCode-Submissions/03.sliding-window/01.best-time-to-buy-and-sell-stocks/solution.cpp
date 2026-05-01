#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            mini = min(mini, prices[i]);
            maxprofit = max(maxprofit, prices[i] - mini);
        }

        return maxprofit;
    }
};

// Time Complexity: O(n) where n is the number of elements in the input array, since we need to iterate through the array once to calculate the maximum profit
// Space Complexity: O(1) since we are using only a constant amount of extra space to store the minimum price and maximum profit