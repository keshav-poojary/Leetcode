# Reverse Bits

## Problem
Given a 32-bit integer, reverse its bits and return the resulting integer.

## Approach

- Initialize a variable `res` to store the reversed number.
- Traverse all 32 bits of the integer from the least significant bit (LSB) to the most significant bit (MSB).
- For each bit:
  - Check whether the current least significant bit is `1`.
  - If it is `1`, set the corresponding bit in the reversed position.
  - Right shift the input number to process the next bit.
- After processing all 32 bits, return the reversed integer.

## Code

```cpp
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
```

## Time Complexity

- **O(32) = O(1)**

Since an integer consists of exactly **32 bits**, the loop always executes 32 iterations. Each iteration performs constant-time operations, making the overall time complexity **O(1)**.

## Space Complexity

- **O(1)**

The algorithm uses only a constant amount of extra memory (`res` and the loop variable), regardless of the input size. Therefore, the space complexity is **O(1)**.