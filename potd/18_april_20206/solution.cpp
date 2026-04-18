#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getReverse(int n)
    {
        int rev = 0;
        while (n > 0)
        {
            int digit = n % 10;
            n = n / 10;
            rev = rev * 10 + digit;
        }

        return rev;
    }

    int mirrorDistance(int n)
    {
        int reverse = getReverse(n);
        return abs(n - reverse);
    }
};