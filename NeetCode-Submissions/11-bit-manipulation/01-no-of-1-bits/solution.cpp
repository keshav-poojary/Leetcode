#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n != 0)
        {
            if (n & 1)
            {
                count += 1;
            }
            n = n >> 1;
        }

        return count;
    }
};

// Time Complexity: O(log n) where n is the input number. This is because we are repeatedly dividing n by 2, which takes O(log n) time.
// Space Complexity: O(1) as we are using a constant amount of space for variables

// n&1 -> check whethere last bit is 1 or 0
// n>>1 -> right shift the bits of n by 1,