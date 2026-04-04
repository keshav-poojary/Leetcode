#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        vector<int> leftSum;
        vector<int> rightSum;
        vector<int> res;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                leftSum.push_back(0);
            }
            else
            {
                leftSum.push_back(sum);
            }
            sum = sum + nums[i];
        }

        sum = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (i == nums.size() - 1)
            {
                rightSum.push_back(0);
            }
            else
            {
                rightSum.push_back(sum);
            }

            sum = sum + nums[i];
        }

        reverse(rightSum.begin(), rightSum.end());

        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(abs(leftSum[i] - rightSum[i]));
        }

        return res;
    }
};