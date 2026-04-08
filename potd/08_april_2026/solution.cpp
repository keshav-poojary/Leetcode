#include <vector>
using namespace std;

class Solution
{
public:
    int modulo = 1e9 + 7;

    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        for (auto query : queries)
        {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            int index = l;

            while (index <= r)
            {
                long long temp = nums[index];
                nums[index] = (temp * v) % (modulo);
                index = index + k;
            }
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res = res ^ nums[i];
        }

        return res;
    }
};