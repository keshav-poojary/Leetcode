#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, long long n)
    {
        double ans = 1;

        if (n < 0)
        {
            n = -n;    // if negative - make it positive
            x = 1 / x; // ans x will be 1/x;
        }

        while (n > 0)
        {
            if (n % 2 != 0)
            {
                ans = ans * x;
                n = n - 1;
            }
            else
            {
                x = x * x;
                n = n / 2;
            }
        }

        return ans;
    }
};

// Time Complexity: O(log n) where n is the input number. This is because we are repeatedly dividing n by 2, which takes O(log n) time.
// Space Complexity: O(1) as we are using a constant amount of space for variables

// algorithm
// 1. If n is negative, make it positive and take the reciprocal of x.
// 2. Initialize ans to 1.
// 3. While n is greater than 0, do the following:
// a. If n is odd, multiply ans by x and decrement n by 1.
// b. If n is even, square x and divide n by 2.

// exmaple
// Input: x = 2.00000, n = 5
// Output: 32.00000
// Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32
// 5 >0, 5 is odd, ans = 1*2 = 2, n = 5-1 = 4
// 4 >0, 4 is even, x = 2*2 = 4, n = 4/2 = 2
// 2 >0, 2 is even, x = 4*4 = 16, n = 2/2 = 1
// 1 >0, 1 is odd, ans = 2*16 = 32, n = 1-1 = 0