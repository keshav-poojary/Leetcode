#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverseBits(int n)
    {
        int res = 0;

        for (int i = 31; i >= 0; i--)
        {
            if (n & 1)
            {
                res = res + pow(2, i);
            }
            n = n >> 1;
        }

        return res;
    }
};

// time complexity -> o(32) -> o(1) because we are iterating through 32 bits of the integer n and performing constant time operations for each bit. Therefore, the overall time complexity is O(1).
// space complexity -> o(1) because we are using a constant amount of extra space to