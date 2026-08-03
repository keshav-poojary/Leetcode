#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int carry = (a & b) << 1;
            a = (a ^ b); // a xor b
            b = carry;
        }
        return a;
    }
};

// time complexity -> o(1) because we are performing a constant number of bitwise operations (AND, XOR, and left shift) for each iteration of the while loop. The number of iterations is limited by the number of bits in the integers a and b, which is a constant value (32 bits for 32-bit integers). Therefore, the overall time complexity is O(1).
// space complexity -> o(1) because we are using a constant amount of extra space to