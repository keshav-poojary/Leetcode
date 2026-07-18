#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int low = 0;
        int high = sqrt(c);

        while (low <= high)
        {
            int a = low;
            int b = high;
            long long sqaureSum = (long long)a * a + (long long)b * b;
            if (sqaureSum == c)
            {
                return true;
            }
            else if (sqaureSum > c)
            {
                high--;
            }
            else
            {
                low++;
            }
        }

        return false;
    }
};